#ifndef TVK_CREATION_H
#define TVK_CREATION_H

#include "pch.h"

#define CAST_TO_STRUCT(t) (reinterpret_cast<t>(_base_type))
#define VK_INSTANCE_CREATE_INFO CAST_TO_STRUCT(const VkInstanceCreateInfo)

namespace TVk
{

    typedef enum StructType : size_t
    {
        TESTSTR,
    } ST;

    const char _base_type = 0;

    struct TVkCoreCreateInfo
    {
    private:
        std::map<std::string, long> _data {};
    public:
        template<typename T>
            inline T& operator[](T)
        {
            T* temp; // add '= {};' if needed. otherwise avoid because of overhead

            std::string name = typeid(temp).name();

            if (_data.count(name) == 0)
            {
                _data[name] = reinterpret_cast<long>(malloc(sizeof(*temp)));
            }

            return reinterpret_cast<T*>(_data[name]);
        };
    };
} // namespace TVks


#endif // TVK_CREATION_H