#pragma once
#include <VulkanRenderer/Core/core.h>
#include <VulkanRenderer/Events/Event.h>
#include <VulkanRenderer/Core/Timestep.h>
#include <string>
#include <GLFW/glfw3.h>
#include <VulkanRenderer/Core/Window.h>

namespace VulkanRenderer{

    /**
     * @class Window 
     * 
     * @function onUpdate
     * @note Updating each frame we see in the window.
     * 
     * @function getNativeWindow
     * @note Returns GLFWwindow as void*
     * 
     * 
    */

    struct WindowProperties{
        WindowProperties(const std::string& t = "Vulkan Renderer", uint32_t w = 1600, uint32_t h = 900) : title(t), width(w), height(h){}

        std::string title;
        uint32_t width, height;
    };

    class ENGINE_API Window{
        // using EventCallbackFn = std::function<void(Event& e)>;
    public:
        using EventCallbackFn = std::function<void(Event& e)>;
        Window(const WindowProperties& properties);

        static Window* create(const WindowProperties& properties = WindowProperties());

        ~Window();

        // @note Updating our layers.
        void onUpdate();

        // @note Keeps track of our event handling system.
        void onEvent(Timestep ts);

        // @note Returns our window instance.
        static Window& Get() { return *instance; }

        // @note Returns our native window (API-agnostic)
        static void* getNativeWindow() { return instance->_windowHandler; }

        bool isVSync() const;
        void setVSync(bool enabled);

        void setEventCallback(const EventCallbackFn& callback){
            data.callback = callback;
        }

    private:
        // @note Used for initializing the core window properties
        void initialize(const WindowProperties& props);

        // @note Cleanly shutting down window management sys.
        void shutdown();

    private:
        WindowProperties properties;
        struct WindowConfigData{
            std::string title = "";
            uint32_t width, height;
            bool isVSyncEnabled;
            EventCallbackFn callback;
        };
        
        GLFWwindow* _windowHandler;
        WindowConfigData data;

        static Window* instance;
    };
};