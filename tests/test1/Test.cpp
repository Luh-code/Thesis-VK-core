//#include <stdio.h>
//#include <iostream>
//#include <string>
#include "TVk-core.h"
//#include "memory.h"

int main()
{
    std::cout<<"Hello World!"<<std::endl;

    TVk::TVkCoreCreateInfo* ci = new TVk::TVkCoreCreateInfo();
    TVk::TVkcore* core = new TVk::TVkcore(ci);

    VkApplicationInfo* vai = core->m_ci[VK_APPLICATION_INFO];
    vai->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vai->pNext = nullptr;
    vai->pApplicationName = "TestApp"; // nullptr if problems occur
    vai->applicationVersion = VK_MAKE_VERSION(1,0,0);
    vai->pEngineName = "Thesis-Vk";
    vai->engineVersion = VK_MAKE_VERSION(0,0,1);
    vai->apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo* vici = core->m_ci[VK_INSTANCE_CREATE_INFO];
    vici->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    vici->pNext = nullptr;
    vici->flags = 0;
    vici->pApplicationInfo = static_cast<const VkApplicationInfo*>(vai);

    uint32_t layerPropertyCount = 0;
    VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount, 0));
    VkLayerProperties* layerProperties = new VkLayerProperties[layerPropertyCount];
    VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount, layerProperties));
    TVk::Info("-----AVAILABLE LAYERS-----");
    for (uint32_t i = 0; i < layerPropertyCount; i++)
    {
        TVk::Info(layerProperties[i].layerName, ": ", layerProperties[i].description);
    }
    TVk::Info("--------------------------");
    delete[] layerProperties;
    const char* enabledLayers[] = {
        "VK_LAYER_KHRONOS_validation"
    };
    vici->enabledLayerCount = 1u;
    vici->ppEnabledLayerNames = enabledLayers;
    vici->enabledExtensionCount = 0u;
    vici->ppEnabledExtensionNames = 0;

    //core->m_ci._data["struct "] = std::make_tuple<TVk::TVkDeleter<nullptr_t>, nullptr>;

    IF_SHF_ERR(core->createVulkanInstance())
    {
        //std::cout<<err.m_value<<std::endl;
        TVk::Err("Error Code: ", static_cast<const char*>(*err), std::to_string(err->m_value).c_str());
        DR_SHF_ERR;
    }
    DR_SHF_IF

    delete core;
    delete ci;
    return 0;
}