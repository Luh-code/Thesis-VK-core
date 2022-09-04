#ifndef TVK_PRESETS_H
#define TVK_PRESETS_H

#include "TVk-creation.h"

namespace TVk
{
    static VkApplicationInfo* windowPresetVkApplicationInfo =
        new VkApplicationInfo {
        //sType:
        VK_STRUCTURE_TYPE_APPLICATION_INFO,
        //pNext:
        nullptr,
        //pApplicationName:
        "Thesis-Vk App", // TODO: Make more user friendly to change
        //applicationVersion:
        1, // TODO: Make more user friendly to change
        //pEngineName:
        "Thesis-Vk", // TODO: Make more user friendly to change
        //engineVersion:
        1, // TODO: Hoop up to version saved in TVk-core.h
        //apiVersion:
        VK_VERSION_1_3, // TODO: Save Vulkan API version in TVk-core.h
    };
    static const char* windowPresetVkInstanceCreateInfoEnabledLayerNames[] = {
        "VK_LAYER_KHRONOS_validation",
    };
    static VkInstanceCreateInfo* windowPresetVkInstanceCreateInfo =
        new VkInstanceCreateInfo {
        //sType:
        VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        //pNext:
        nullptr,
        //flags:
        0x0,
        //pApplicationInfo;
        windowPresetVkApplicationInfo,
        //enabledLayerCount:
        1,
        //ppEnabledLayerNames:
        windowPresetVkInstanceCreateInfoEnabledLayerNames,
        //enabledExtensionCount:
        0, // TODO!: Make more user friendly to change
        //enabledExtensionNames:
        nullptr, // TODO!: Make more user friendly to change
    };
    static InstanceCreateInfo* windowPresetInstanceCreateInfo =
        new InstanceCreateInfo {
        //m_customizationFlags:
        ALL,
        //m_customCreateInfo:
        windowPresetVkInstanceCreateInfo,
    };
    static TVkcoreCreateInfo windowPreset = {
        //m_presetMode:
        CUSTOM,
        //m_instanceCreateInfo:
        windowPresetInstanceCreateInfo,
    };
}

#endif // TVK_PRESETS_H