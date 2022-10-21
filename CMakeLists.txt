cmake_minimum_required(VERSION 3.7)
project(ThesisVk VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(${PROJECT_SOURCE_DIR}/dependencies/SDL)

include(CTest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(PREPROCESSOR_DEFINITIONS EZV_SUPPORT_SDL LHG_VERBOSE EZV_INFO_OUTPUT LHG_LINUX)

#find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

add_compile_definitions(${PREPROCESSOR_DEFINITIONS})
#add_compile_options("-O2")

set(SOURCE ${PROJECT_SOURCE_DIR}/src/TVk-core.cpp)

# Create EzV as a Static Library
add_library(TVk STATIC ${SOURCE})
target_compile_definitions(TVk PUBLIC ${PREPROCESSOR_DEFINITIONS})
target_include_directories(TVk PUBLIC ${PROJECT_SOURCE_DIR}/dependencies/FlagEx/include
                                ${PROJECT_SOURCE_DIR}/dependencies/Sheriff/include
                                #${PROJECT_SOURCE_DIR}/dependencies/Vulkan/1.3.216.0/x86_64/include
                                ${Vulkan_INCLUDE_DIRS}
                                ${SDL2_INCLUDE_DIRS})
target_link_libraries(TVk PUBLIC #${PROJECT_SOURCE_DIR}/dependencies/Vulkan/1.3.216.0/x86_64/lib/libvulkan.so
                                #${Vulkan_LIBRARIES}
                                ${SDL2_LIBRARIES})
#target_precompile_headers(TVk PUBLIC ${PROJECT_SOURCE_DIR}/src/pch.h)
# Setup Testing
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
