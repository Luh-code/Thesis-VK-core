//#include "pch.h"
#include "TVk-core.h"

namespace TVk
{
    shf::RetV* TVkcore::createVulkanInstance()
    {
        VkInstanceCreateInfo* temp = static_cast<VkInstanceCreateInfo*>(m_ci[VK_INSTANCE_CREATE_INFO]);
        if(vkCreateInstance(
            temp,
            0,//m_ci[VK_ALLOCATION_CALLBACKS],
            m_data->p_instance
            ) != VK_TRUE)
        {
            return new shf::RetV(shfT, ERR_INSTANCE_CREATION);
        }

        return new shf::RetV(shfT, ERR_NONE);
    }
}