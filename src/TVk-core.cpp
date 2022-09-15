#include "TVk-core.h"

namespace TVk
{

    shf::RetV TVkcore::_configTree()
    {
        // TODO: Override preset data with custom data from/in createInfo
        switch (m_ci->m_presetMode) // select correct preset
        {
            case TP::CUSTOM:
                break;
            case TP::PRESET_WINDOW:
                m_selectedPreset = windowPreset;
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