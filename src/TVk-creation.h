#ifndef TVK_CREATION_H
#define TVK_CREATION_H

#include "TVk-modular.h"

namespace TVk
{
    // * Substructs

    // Base struct for all CreateInfo's
    template<typename DataStruct, typename CustomizationFlags, typename... Args>
        struct GenericCreateInfo
    {
        CustomizationFlags m_customizationFlags;
        DataStruct* p_customCreateInfo;

        void _compile(DataStruct& _data, Args... _custom);
    };

    // * CreateInfos

    typedef enum struct ApplicationInfoFlags: FLAG
    {
        NONE = 0b0,
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
    struct ApplicationInfo :
        public GenericCreateInfo<VkApplicationInfo, ApplicationInfoFlags>
    {
        compile
    };

    typedef enum struct InstanceCustomizationFlags : FLAG
    {
        NONE = 0b0,
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
    struct InstanceCreateInfo: // * InstanceCreateInfo
        public GenericCreateInfo<VkInstanceCreateInfo, InstanceCustomizationFlags>
    {
        ApplicationInfo* p_applicationInfo;
        void _compile(VkInstanceCreateInfo& _data) // ! Fuck
        {
            modifyStruct<
                VkStructureType,
                const void*,
                VkInstanceCreateFlags,
                const VkApplicationInfo*,
                uint32_t,
                const char* const*,
                uint32_t,
                const char* const*,
                VkInstanceCreateInfo>
                (&_data, static_cast<FLAG>(m_customizationFlags), p_customCreateInfo);
            p_applicationInfo->_compile(p_applicationInfo);
        }
    };

    // * TVkcore Stuff
    /**
     * @brief Flags for setting up TVkcore via TVkcoreCreateInfo
     * 
     */
    typedef enum struct TVkcorePresets : uint32_t
    {
        CUSTOM = 0,
        PRESET_WINDOW = 1,
        PRESET_HEADLESS = 2
    } TP;
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