#include <VulkanRenderer/Core/Application.h>

namespace VulkanRenderer{
    Application* Application::instance = nullptr;

    Application::Application(const std::string& name, ApplicationCommandLineArgs args){
        isRunning = true;
        instance = this;
        window = std::unique_ptr<Window>(Window::create(name));
        window->setEventCallback(bind_function(this, &Application::onEvent));
    }

    Application::~Application(){}

    void Application::Run(){
        while(isRunning){
            float time = (float)glfwGetTime();
            Timestep timestep = time - lastFrameTime;
            lastFrameTime = time;

            // printf("Running Mainloop!\n");
            window->onUpdate();

            // glfwSwapBuffers(window);
        }
    }

    bool Application::onWindowClose(WindowCloseEvent& e){
        isRunning = false;
        return true;
    }

    bool Application::onWindowResize(WindowResizeEvent& e){
        return true;
    }

    void Application::onEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(bind_function(this, &Application::onWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(bind_function(this, &Application::onWindowResize));

    }
};