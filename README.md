# Thesis-VK-core
## THIS REPO IS FROZEN
For a while, I won't work on this. Ill get to it eventually tho.

## WARNING
This repo has barely anything in it right now, and is not usable yet. If you are interested in the concept watch the project to get notified, whenever somehing changes.  
The features listed below are what the project will become, not what it is right now. This message will be removed, when the core functionality is implemented!

## General information
Thesis Vk core is an easy to use, blazingly fast, highly configurable, scaleable, Vulkan abstraction with builtin lifetime management for your cross-platform Vulkan application.
Thesis Vk core (TVk-core) is available on Windows and Linux. Mac Os and mobile platforms are not supported yet. This will be subject to change in the future though.

TVk-core adapts the same approach as Vulkan for object creation, by using creation structs. This allows for a very highly configurable API, but leaves the option to make it quick, if it just needs to work right now.
Multiple presets are baked in, such as one for windowed and one for headless usage (so to say just for compute shaders, or rendering to a file).

For windowed usecases you can integrate TVk-into any window library you'd like. Through expansions TVk can also natively create a SDL or GLTF window, and manage its lifecycle.

The console output is also highly configurable, and should work fine with any logger you throw at it.
