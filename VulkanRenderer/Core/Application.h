#pragma once
#include <VulkanRenderer/Core/core.h>
#include <VulkanRenderer/Core/Window.h>
#include <VulkanRenderer/Events/ApplicationEvent.h>
#include <VulkanRenderer/Core/LayerStack.h>
#include <cassert>
#include <assert.h>

namespace VulkanRenderer{
    struct ApplicationCommandLineArgs{
		int count = 0;
		char** args = nullptr;

		const char* operator[](int index) const {
			assert(index < count);
			return args[index];
		}
	};

    class Application{
    public:
        Application(const std::string& name="Vulkan Renderer", ApplicationCommandLineArgs args = ApplicationCommandLineArgs{});
        ~Application();

        void Run();

        void onEvent(Event& event);

        static Application& Get() { return *instance; }

        static Window& GetWindow() { return *instance->window; }

        void close(){ isRunning = false; }

        void pushLayer(Layer* layer);
        void pushOverlay(Layer* layer);

    private:
        bool onWindowClose(WindowCloseEvent& e);
        bool onWindowResize(WindowResizeEvent& e);

    private:
        bool isRunning;
        static Application* instance;
        Ref<Window> window;
        LayerStack layerStack;
        float lastFrameTime = 0.0f; // @note Time it took rendering prev frame.
    };

    Application* CreateApplication(const ApplicationCommandLineArgs& args);
};