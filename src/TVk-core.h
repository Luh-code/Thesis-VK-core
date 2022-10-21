#ifndef TVK_CORE_H
#define TVK_CORE_H

// * Project includes
#include "pch.h" // Precompiled
#include "TVk-log.h"
#include "TVk-creation.h"
#include "TVk-presets.h"
//#include "memory.h"

// * Imported includes

// * Definitions
#define VK_FAIL(val) if((val) != VK_SUCCESS)
#define ASSERT_VULKAN(val) VKFAIL(val) { TVk::Crit("An error occured in an attempted vulkan call"); assert(false); }
#define VK(f) f
#define VKA(f) ASSERT_VULKAN(VK(f))
#define VKF(val) VK_FAIL(val)

namespace TVk
{
    using string=std::string;

    typedef enum TVkVersion : uint32_t
    {
        MAJOR = 1,
        MINOR = 0,
        PATCH = 0
    } TVkVersion;

    // Vulkan Objects
    struct TVkData
    {
        VkInstance* p_instance;
    };

    /**
     * @brief Core class of Thesis-Vk
     *
     */
    class TVkcore
    {
        using RetV=shf::RetV;
        using CreateInfo=TVkCoreCreateInfo;
    private:
        std::vector<RetV(*)(void)> m_dprocess; // ? Maybe dont do this

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

        RetV _configureInstanceCreateInfo
            (const CreateInfo*& _pre, const CreateInfo*& _ci);

        // Utils
        template<typename T>
            inline int array_count(T* _a) // ? Inline for now; maybe make macro
            // ? Rename to _array_count
        {
            return (sizeof(_a) / sizeof((_a)[0]));
        }
    public:
        // * Vulkan Objects
        TVkData* m_data = new TVkData(); // TODO: add to destructor

        enum Errors : int32_t
        {
            ERR_NONE = 0,
            ERR_GENERIC = -1,
            ERR_INSTANCE_CREATION = -2,
        };
        shf::Territory shfT = shf::Territory("TVkcore", ERR_NONE); // ? Make std::shared_ptr to handle error, when object deleted

        CreateInfo* p_ci;
        CreateInfo& m_ci;

        // * Constructor and Destructor
        TVkcore(CreateInfo* ci)
         : p_ci(ci), m_ci(*p_ci)
        {
        }
        //~TVkcore();

        // * Public Methods
        /**
         * @brief Creates a VkInstance
         *
         * @return RetV
         */
        RetV* createVulkanInstance();
        /**
         * @brief Selects a physical device(GPU), defined in the createInfo struct
         *
         * @return RetV
         */
        RetV selectPhysicalDevice() = delete;
        /**
         * @brief Create a VkDevice based on selected physical device
         *
         * @return RetV
         */
        RetV createLogicalDevice() = delete;
        /**
         * @brief Create a VkSwapchainKHR
         *
         * @return RetV
         */
        RetV createSwapchain() = delete;
        /**
         * @brief Destroys the swapchain
         *
         */
        void destroySwapchain() = delete;
        /**
         * @brief Create a the amount of frame buffers defined in the createInfo
         *
         * @return RetV
         */
        RetV createFrameBuffers() = delete;
        /**
         * @brief Destroys all frame buffers
         *
         */
        void destroyFrameBuffers() = delete;
        /**
         * @brief Create Renderpasses as defined in the createInfo
         *
         * @return RetV
         */
        RetV createRenderpasses() = delete;
        /**
         * @brief Destroys all Renderpasses
         *
         */
        void destroyRenderpasses() = delete;
        /**
         * @brief Sets this TVkcore object up
         *
         * @return RetV
         */
        RetV setup() = delete;

        //RetV(* pp_cprocess[])(void); // Function pointer[] for creation process
    };
}

#endif // TVK_CORE_H
