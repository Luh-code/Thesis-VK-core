#include <stdio.h>
#include <string>
#include "TVk-core.h"

int main()
{
    using TestStr=TVk::TestStr;

    /*TestStr* t = new TestStr();
    t->a=0;
    t->b=0;
    t->c=0;
    t->d=0;
    TestStr* t2 = new TestStr();
    FLAG fl = 0b1010;
    TVk::Debug("t:");
    TVk::extractStruct<double, int, float, char>(t, true);
    TVk::Debug("t2:");
    TVk::extractStruct<double, int, float, char>(t2, true);
    TVk::modifyStruct<double, int, float, char>(t, fl, t2);
    TVk::Debug("t->modified 1010:");
    TVk::extractStruct<double, int, float, char>(t, true);*/

    VkApplicationInfo* vkApplicationInfo = new VkApplicationInfo{};
    vkApplicationInfo->pApplicationName = "TVk Test application 1";

    TVk::ApplicationInfo* applicationInfo = new TVk::ApplicationInfo
    {
        //m_customizationFlags:
        TVk::AI::PAPPLICATIONNAME,
        //p_customCreateInfo:
        vkApplicationInfo,
    };

    TVk::InstanceCreateInfo* instanceCreateInfo = new TVk::InstanceCreateInfo
    {
        //m_customizationFlags:
        TVk::ICI::NONE,
        //p_customCreateInfo:
        nullptr,
        //p_applicationInfo:
        applicationInfo,
    };

    TVk::TVkcoreCreateInfo* createInfo = new TVk::TVkcoreCreateInfo
    {
        //m_presetMode:
        TVk::TP::PRESET_HEADLESS,
        //m_instanceCreateInfo:
        instanceCreateInfo,
    };

    TVk::TVkcore* tvkcore = new TVk::TVkcore(*createInfo);

    tvkcore->_createConfigTree();

    return 0;
}