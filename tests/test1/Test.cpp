//#include <stdio.h>
//#include <iostream>
//#include <string>
#include "TVk-core.h"
//#include "memory.h"

int main()
{
    TVk::TVkCoreCreateInfo* ci = new TVk::TVkCoreCreateInfo();
    TVk::TVkcore* core = new TVk::TVkcore(ci);

    VkApplicationInfo* vai = core->m_ci[VK_APPLICATION_INFO];
    vai->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    vai->pNext = nullptr;
    vai->pApplicationName = "TestApp"; // nullptr if problems occur
    vai->applicationVersion = 1;
    vai->pEngineName = "Thesis-Vk";
    vai->engineVersion = 1;
    vai->apiVersion = VK_VERSION_1_3;

    VkInstanceCreateInfo* vici = core->m_ci[VK_INSTANCE_CREATE_INFO];
    vici->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    vici->pNext = nullptr;
    vici->flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
    vici->pApplicationInfo = static_cast<const VkApplicationInfo*>(vai);
    vici->enabledLayerCount = 0u;
    //vici->ppEnabledLayerNames = nullptr;
    vici->enabledExtensionCount = 0u;
    //vici->ppEnabledExtensionNames = nullptr;

    //core->m_ci._data["struct "] = std::make_tuple<TVk::TVkDeleter<nullptr_t>, nullptr>;

    IF_SHF_ERR(core->createVulkanInstance())
    {
        //std::cout<<err.m_value<<std::endl;
        TVk::Err("Error Code: ", static_cast<const char*>(err), std::to_string(err.m_value).c_str());
    }

    delete core;
    delete ci;
    return 0;
}