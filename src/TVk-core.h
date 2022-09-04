#ifndef TVK_CORE_H
#define TVK_CORE_H

// * Project includes
#include "pch.h" // Precompiled
#include "TVk-log.h"
#include "TVk-modular.h"
#include "TVk-creation.h"

// * Imported includes

// * Definitions
#define ASSERT_VULKAN(val) if((val) != VK_SUCCESS) { TVk::Crit("An error occured in an attempted vulkan call"); assert(false); }
#define VK(f) f
#define VKA(f) ASSERT_VULKAN(VK(f))

namespace TVk
{
    using string=std::string;

   /* struct TVkcoreInstanceCreateInfo
    {
        typedef enum TVkcoreInstanceCreateInfoFlags : FLAG
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
        } CreateInfoFlags;
        CreateInfoFlags creationFlags;
        VkInstanceCreateInfo createInfo;
    };*/

    struct TVkcoreCreateInfo
    {
        //TVkcoreInstanceCreateInfo
    };

    /**
     * @brief Core class of Thesis-Vk
     *
     */
    class TVkcore
    {
        using RetV=shf::RetV;
        using CreateInfo=TVkcoreCreateInfo;
    private:
        std::vector<RetV(*)(void)> m_dprocess;

        // * Private Methods

        /**
         * @brief Creates a Renderpass
         *
         * @return RetV
         */
        RetV _createRenderpass();
        /**
         * @brief Creates a Rendersubpass
         *
         * @return RetV
         */
        RetV _createRendersubpass();
        // Utils
        template<typename T>
            inline int array_count(T* _a) // ? Inline for now maybe make macro
        {
            return (sizeof(_a) / sizeof((_a)[0]));
        }
    public:
        /**
         * @brief
         *
         *
         */
        enum Errors : int32_t
        {
            ERR_NONE = 0,
            ERR_GENERIC = -1,
        };
        shf::Territory shfT = shf::Territory("TVkcore", ERR_NONE); // ? Make std::shared_ptr to handle error, when object deleted

        CreateInfo* m_ci;

        // * Constructor and Destructor
        TVkcore();
        TVkcore(CreateInfo& _ci)
        {
            setup(_ci);
        }
        ~TVkcore();

        // * Public Methods
        /**
         * @brief Creates a VkInstance
         *
         * @return RetV
         */
        RetV createVulkanInstance();
        /**
         * @brief Selects a physical device(GPU), defined in the createInfo struct
         *
         * @return RetV
         */
        RetV selectPhysicalDevice();
        /**
         * @brief Create a VkDevice based on selected physical device
         *
         * @return RetV
         */
        RetV createLogicalDevice();
        /**
         * @brief Create a VkSwapchainKHR
         *
         * @return RetV
         */
        RetV createSwapchain();
        /**
         * @brief Destroys the swapchain
         *
         */
        void destroySwapchain();
        /**
         * @brief Create a the amount of frame buffers defined in the createInfo
         *
         * @return RetV
         */
        RetV createFrameBuffers();
        /**
         * @brief Destroys all frame buffers
         *
         */
        void destroyFrameBuffers();
        /**
         * @brief Create Renderpasses as defined in the createInfo
         *
         * @return RetV
         */
        RetV createRenderpasses();
        /**
         * @brief Destroys all Renderpasses
         *
         */
        void destroyRenderpasses();

        /**
         * @brief Sets this TVkcore object up
         *
         * @param _ci
         * @return RetV
         */
        RetV setup(CreateInfo& _ci)
        {
            this->m_ci = &_ci;
            return setup();
        }
        /**
         * @brief Sets this TVkcore object up
         *
         * @return RetV
         */
        RetV setup();

        RetV(* pp_cprocess[])(void); // Function pointer[] for creation process
    };
}

#endif // TVK_CORE_H
