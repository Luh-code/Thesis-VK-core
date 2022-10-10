#include "TVk-core.h"

namespace TVk
{
    shf::RetV TVkcore::createVulkanInstance()
    {
        /*VkInstanceCreateInfo ci = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};

        VKA(vkCreateInstance(
            &ci,
            &instance
        ));*/
        return shf::RetV(shfT, ERR_NONE);
    }
}