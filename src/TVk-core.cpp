#include "TVk-core.h"

namespace TVk
{
    shf::RetV TVkcore::_createConfigTree()
    {
        // TODO: Override preset data with custom data from/in createInfo
        CreateInfo* preset = nullptr;
        switch (m_ci->m_presetMode)
        {
            case TP::CUSTOM:
                break;
            case TP::PRESET_WINDOW:
            preset = windowPreset;
                break;
            case TP::PRESET_HEADLESS:
                Crit("Headless preset unavailable!");
                break;
            default:
                Crit("Preset unavailable");
        }

        return shf::RetV(shfT, ERR_NONE);
    }

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