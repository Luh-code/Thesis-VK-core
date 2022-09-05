#ifndef TVK_CREATION_H
#define TVK_CREATION_H

namespace TVk
{
    // * Substructs

    // Base struct for all CreateInfo's
    template<typename DataStruct, typename CustomizationFlags>
        struct GenericCreateInfo
    {
        CustomizationFlags m_customizationFlags;
        DataStruct* p_customCreateInfo;
    };

    // * CreateInfos

    typedef enum struct ApplicationInfoFlags: FLAG
    {
        STYPE = 0b1<<0,
        PNEXT = 0b1<<1,
        PAPPLICATIONNAME = 0b1<<2,
        APPLICATIONVERSION = 0b1<<3,
        PENGINENAME = 0b1<<4,
        ENGINEVERSION = 0b1<<5,
        APIVERSION = 0b1<<6,
        ALL = STYPE | PNEXT | PAPPLICATIONNAME |
            APPLICATIONVERSION | PENGINENAME | ENGINEVERSION |
            APIVERSION,
    } AI;
    struct ApplicationInfo : GenericCreateInfo<VkApplicationInfo, ApplicationInfoFlags> {};

    typedef enum struct InstanceCustomizationFlags : FLAG
    {
        STYPE = 0b1<<0,
        PNEXT = 0b1<<1,
        FLAGS = 0b1<<2,
        PAPPLICATIONINFO = 0b1<<3,
        ENABLEDLAYERCOUNT = 0b1<<4,
        PPENABLEDLAYERNAMES = 0b1<<5,
        ENABLEDEXTENSIONCOUNT = 0b1<<6,
        PPENABLEDEXTENSIONNAMES = 0b1<<7,
        ALL = STYPE | PNEXT | FLAGS | PAPPLICATIONINFO |
            ENABLEDLAYERCOUNT | PPENABLEDLAYERNAMES | ENABLEDEXTENSIONCOUNT | PPENABLEDEXTENSIONNAMES
    } ICI;
    struct InstanceCreateInfo : GenericCreateInfo<VkInstanceCreateInfo, InstanceCustomizationFlags>
    {
        ApplicationInfo* p_applicationInfo;
    };

    // * TVkcore Stuff
    /**
     * @brief Flags for setting up TVkcore via TVkcoreCreateInfo
     * 
     */
    typedef enum TVkcorePresets : uint32_t
    {
        CUSTOM = 0,
        PRESET_WINDOW = 1,
        PRESET_HEADLESS = 2
    } TVkcorePresets;
    /**
     * @brief Struct for setting up TVkcore fully
     * 
     */
    struct TVkcoreCreateInfo
    {
        TVkcorePresets m_presetMode;
        InstanceCreateInfo* p_instanceCreateInfo;
    };
} // namespace TVk


#endif // TVK_CREATION_H