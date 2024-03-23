#include <VulkanRenderer/Core/Window.h>
#include <vulkan/vulkan.h>
#include <VulkanRenderer/Core/RendererLogger.h>
#include <VulkanRenderer/Events/KeyEvent.h>
#include <VulkanRenderer/Events/MouseEvent.h>
#include <VulkanRenderer/Events/ApplicationEvent.h>

namespace VulkanRenderer{
    Window* Window::instance = nullptr;

    static void GLFWErrorCallback(int error, const char* description){
        coreLogError("GLFWErrorCallback MSG --- (Error cCode -> {}): {}", error, description);
    }

    Window* Window::create(const WindowProperties& properties){
        return new Window(properties);
    }

    Window::Window(const WindowProperties& props) {
        instance = this;

        initialize(props);
    }

    Window::~Window(){
        shutdown();
    }

    void Window::onUpdate(){
        glfwPollEvents();
    }

    void Window::onEvent(Timestep ts){}

    void Window::initialize(const WindowProperties& props){
        data.width = props.width;
        data.height = props.height;
        data.title = props.title;
        coreLogInfo("Initializing Window {} ({} x {})", props.title, props.width, props.height);

        if(!glfwInit()){
            coreLogError("Could not initialize GLFWInit()!");
            glfwSetErrorCallback(GLFWErrorCallback);
            return;
        }

        // glfwWindowHint(GLFW_CONTEXT_I)
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        // Have to specify this as a requirement before using opengl/glad or else you'll get a segfault
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, true);

        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        coreLogInfo("Extension instances available are -- {}", extensionCount);


        _windowHandler = glfwCreateWindow((int)data.width, (int)data.height, data.title.c_str(), nullptr, nullptr);

        glfwSetWindowUserPointer(_windowHandler, &data);

        // Setting GLFW Event callbacks
        // This is creating a WindowResizeEvent callback
        glfwSetWindowSizeCallback(_windowHandler, [](GLFWwindow* window, int w, int h){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);
            data.width = w;
            data.height = h;

            // This is how we are going to be setting the callback from Application to event
            WindowResizeEvent event(w, h);
            data.callback(event);
        });

        // This is how we are dispatching the WindowCloseEvent callbacks to that specific event.
        glfwSetWindowCloseCallback(_windowHandler, [](GLFWwindow* window){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.callback(event);
        });

        // - A thing to NOTE is that at some point because this key code is GLFW-specific.
        // We should definitely convert the key code into our engines specific key code because on other platforms
        // - where we don't use GLFW key codes, and do not want to be tied to only using those GLFW key codes.
        // - To basically have our own.
        glfwSetKeyCallback(_windowHandler, [](GLFWwindow* window, int key, int scancode, int action, int modes){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);

            // So when are doing a key call back the function takes in GLFWwindow, int, int, int
            //  action specified what action is occuring when with our key events, like are we pressing, releasing or repeating key events.
            // Event Usage: event(key, count) and for release is event(key)
            switch(action){
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(static_cast<KeyCode>(key), 0);
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(static_cast<KeyCode>(key));
                    data.callback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(static_cast<KeyCode>(key), 1);
                    data.callback(event);
                    break;
                }
            }
        });

        // Callback for the Key Type Event
        // Essentially for typing text into a text box
        // NOTE: keycode is the character that we are currently typing
        glfwSetCharCallback(_windowHandler, [](GLFWwindow* window, unsigned int keycode){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(static_cast<KeyCode>(keycode));
            data.callback(event);
        });

        // Setting up our event dispatchers for mouse events (ref to more a descriptive explanation at the top for key events as it applied to mouse events)
        glfwSetMouseButtonCallback(_windowHandler, [](GLFWwindow* window, int button, int action, int modes){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);

            switch(action){
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(static_cast<MouseCode>(button));
                    data.callback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
                    data.callback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(_windowHandler, [](GLFWwindow* window, double xOffset, double yOffset){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.callback(event);
        });

        glfwSetCursorPosCallback(_windowHandler, [](GLFWwindow* window, double xPos, double yPos){
            WindowConfigData& data =  *(WindowConfigData *)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data.callback(event);
        });
    }

    void Window::shutdown(){
        glfwDestroyWindow(_windowHandler);
        glfwTerminate();
    }

    bool Window::isVSync() const {
        return data.isVSyncEnabled;
    }

    void Window::setVSync(bool enabled){

        // @note How we can enable VSync
        if(enabled){
            glfwSwapInterval(1);
        }
        else{
            glfwSwapInterval(0);
        }

        data.isVSyncEnabled = enabled;
    }
};