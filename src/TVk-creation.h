#ifndef TVK_CREATION_H
#define TVK_CREATION_H

#include "pch.h"

#define CAST_TO_STRUCT(t) (reinterpret_cast<t*>(TVk::_base_pointer))
#define VK_INSTANCE_CREATE_INFO CAST_TO_STRUCT(VkInstanceCreateInfo)
#define VK_ALLOCATION_CALLBACKS CAST_TO_STRUCT(VkAllocationCallbacks)
#define VK_APPLICATION_INFO CAST_TO_STRUCT(VkApplicationInfo)
#define CTS(t) CAST_TO_STRUCT(t)

namespace TVk
{

    // * 9 Bytes overhead, reduce if possible
    static char _base_type = 0;
    static char* _base_pointer = &_base_type;

    class TVkDeleterBase
    {
    private:
        virtual void del(uint64_t addr) = 0;
        friend struct TVkCoreCreateInfo;
    };

    template<typename T>
        class TVkDeleter : public TVkDeleterBase
    {
    private:
        void del(uint64_t addr)
        {
            free(reinterpret_cast<T>(addr));
            delete this;
        }
    };

    template <typename T, typename G>
        struct not_convertible_tp
    {
    };

    template<class From, class To>
        concept NotSomeType = !std::convertible_to<From, To>;
    template<class From, class To>
        concept OnlySomeType = std::convertible_to<From, To>;

    struct TVkCoreCreateInfo
    {
    public:
        std::map<std::string, std::tuple<uint64_t, TVkDeleterBase*>> _data =
            std::map<std::string, std::tuple<uint64_t, TVkDeleterBase*>>();
    public:
    // TODO: update when cpp23 releases, to use (t, int inx) as arguments for [], for structs, that can appear multiple times

        /* template<NotSomeType<TVkCoreCreateInfo> T, OnlySomeType<TVkCoreCreateInfo> Ret>
            Ret& operator[](T)
        {
            return *this;
        };*/

        template<NotSomeType<TVkCoreCreateInfo> T, NotSomeType<TVkCoreCreateInfo> R = T>
            R operator[](T)
        {
            T temp;

            std::string name = typeid(*temp).name();
            //std::cout<<name<<std::endl;

            if (_data.count(name) == 0)
            {
                TVkDeleterBase* temp2 = new TVkDeleter<T>();// reinterpret_cast<TVkDeleter<T>*>(malloc(sizeof(TVkDeleter<T>)));
                _data[name] = std::make_tuple(reinterpret_cast<uint64_t>(malloc(sizeof(*temp))), temp2);
            }

            return reinterpret_cast<T>(std::get<0>(_data[name]));
        };

        ~TVkCoreCreateInfo()
        {
            for(auto const& [key, val] : _data)
            {
                //std::cout<<"deleted "<<sizeof(*std::get<0>(val))<<"bytes\n";
                auto temp = std::get<1>(val);
                temp->del(std::get<0>(val));
            }
        };
    };
} // namespace TVks


#endif // TVK_CREATION_H