#pragma once
#include <cstdint>

namespace VulkanRenderer{
	typedef enum class MouseCode : uint16_t{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;
}

#define ENGINE_MOUSE_BUTTON_0      ::VulkanRenderer::Mouse::Button0
#define ENGINE_MOUSE_BUTTON_1      ::VulkanRenderer::Mouse::Button1
#define ENGINE_MOUSE_BUTTON_2      ::VulkanRenderer::Mouse::Button2
#define ENGINE_MOUSE_BUTTON_3      ::VulkanRenderer::Mouse::Button3
#define ENGINE_MOUSE_BUTTON_4      ::VulkanRenderer::Mouse::Button4
#define ENGINE_MOUSE_BUTTON_5      ::VulkanRenderer::Mouse::Button5
#define ENGINE_MOUSE_BUTTON_6      ::VulkanRenderer::Mouse::Button6
#define ENGINE_MOUSE_BUTTON_7      ::VulkanRenderer::Mouse::Button7
#define ENGINE_MOUSE_BUTTON_LAST   ::VulkanRenderer::Mouse::ButtonLast
#define ENGINE_MOUSE_BUTTON_LEFT   ::VulkanRenderer::Mouse::ButtonLeft
#define ENGINE_MOUSE_BUTTON_RIGHT  ::VulkanRenderer::Mouse::ButtonRight
#define ENGINE_MOUSE_BUTTON_MIDDLE ::VulkanRenderer::Mouse::ButtonMiddle