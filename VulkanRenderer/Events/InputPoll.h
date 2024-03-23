#pragma once
#include <VulkanRenderer/Core/core.h>
#include <VulkanRenderer/Events/KeyCodes.h>
#include <VulkanRenderer/Events/MouseEvent.h>
#include <glm/glm.hpp>

namespace VulkanRenderer{

    class ENGINE_API InputPoll{
        using MousePosition = glm::vec2;
    public:

        inline static bool isKeyPressed(KeyCode key){
            return instance->isKeyPressedImpl(key);
        }
        inline static bool isMouseButtonPressed(Mouse button){
            return instance->isMouseButtonPressedImpl(button);
        }

        inline static MousePosition getMousePosition();

        inline static float getMouseX();

        inline static float getMouseY();

    protected:
        virtual bool isKeyPressedImpl(KeyCode keycode);
        virtual bool isMouseButtonPressedImpl(Mouse button);
        virtual MousePosition getMousePositionImpl();

        virtual float getMouseXImpl();
        virtual float getMouseYImpl();
    private:
        static InputPoll* instance;
    };
};