#include <stdio.h>
#include <iostream>
#include <string>
#include "TVk-core.h"

int main()
{
    printMemoryUsage();
    TVk::TVkCoreCreateInfo* i0 = new TVk::TVkCoreCreateInfo();
    TVk::TVkCoreCreateInfo& ir = *i0;// *(*i0)[VK_INSTANCE_CREATE_INFO];
    std::cout<<"Before: "<<ir[VK_INSTANCE_CREATE_INFO]->enabledLayerCount<<std::endl;
    printMemoryUsage();
    ir[VK_INSTANCE_CREATE_INFO]->enabledLayerCount = 5;
    printMemoryUsage();
    std::cout<<"After: "<<ir[VK_INSTANCE_CREATE_INFO]->enabledLayerCount<<std::endl;
    std::cout<<"Test\n";

    delete i0;
    printMemoryUsage();
    return 0;
}