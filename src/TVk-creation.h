#ifndef TVK_CREATION_H
#define TVK_CREATION_H

#include "pch.h"

namespace TVk
{
    typedef enum StructType : size_t
    {

    } ST;

    void 

    struct TVkCoreCreateInfo
    {
    private:
        std::map _data<StructType, byte*> = {};
    public:
        template<typename T>
            inline T operator[](T type)
        {
            if (_data[type] == nullptr)
            {

            }
        };
    };
} // namespace TVk


#endif // TVK_CREATION_H