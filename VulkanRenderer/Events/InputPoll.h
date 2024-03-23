#pragma once
#include <VulkanRenderer/Core/core.h>
#include <glm/glm.hpp>

namespace VulkanRenderer{
    class KeyCode;
    class Mouse;

    class ENGINE_API InputPoll{
        using MousePosition = glm::vec2;
    public:

        inline static bool isKeyPressed(KeyCode key);
        inline static bool isMouseButtonPressed(Mouse button);

        inline static MousePosition getMousePosition();

        inline static float getMouseX();

        inline static float getMouseY();

    protected:
        virtual bool isKeyPressedImpl(KeyCode keycode) = 0;
        virtual bool isMouseButtonPressedImpl(Mouse button) = 0;
        virtual MousePosition getMousePositionImpl() = 0;

        virtual float getMouseXImpl() = 0;
        virtual float getMouseYImpl() = 0;
    private:
    static InputPoll* instance;
    };
};