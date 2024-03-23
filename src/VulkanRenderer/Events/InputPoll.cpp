#include <VulkanRenderer/Events/InputPoll.h>
#include <GLFW/glfw3.h>
#include <VulkanRenderer/Core/Application.h>

namespace VulkanRenderer{
    InputPoll* InputPoll::instance = new InputPoll();

	bool InputPoll::isKeyPressedImpl(Key keycode){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetKey(window, static_cast<int32_t>(keycode));

		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool InputPoll::isMouseButtonPressedImpl(Mouse button){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		auto state = glfwGetMouseButton(window, static_cast<int32_t>(button));

		return state == GLFW_PRESS;
	}

	float InputPoll::getMouseXImpl(){
		return getMousePositionImpl().x;
	}

	float InputPoll::getMouseYImpl(){
		return getMousePositionImpl().y;
	}

	glm::vec2 InputPoll::getMousePositionImpl(){
		auto window = static_cast<GLFWwindow *>(Application::Get().GetWindow().getNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		glm::vec2 position = {(float)xpos, (float)ypos};
		return position;
	}
};