#ifndef TVK_CREATION_H
#define TVK_CREATION_H

namespace TVk
{
    // * Base struct for all CreateInfo's
    template<typename DataStruct, typename CustomizationFlags>
        struct GenericCreateInfo
    {
        CustomizationFlags m_customizationFlags;
        DataStruct m_customCreateInfo;
    };

    typedef enum InstanceCustomizationFlags : FLAG
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
    } InstanceCustomizationFlags;
    struct InstanceCreateInfo : GenericCreateInfo<VkInstanceCreateInfo, InstanceCustomizationFlags>{};
} // namespace TVk


#endif // TVK_CREATION_H