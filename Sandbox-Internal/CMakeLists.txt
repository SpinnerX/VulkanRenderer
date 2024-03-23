cmake_minimum_required(VERSION 3.15)

project(VulkanStarterProject)

find_package(VulkanRenderer REQUIRED)
# if(UNIX AND NOT APPLE)
find_package(glfw3 REQUIRED)
# endif(UNIX AND NOT APPLE)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(Vulkan REQUIRED)
# find_package(GLUT REQUIRED)

find_package(imgui REQUIRED)
find_package(ImGuizmo REQUIRED)
# find_package(Vulkan REQUIRED)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(glm REQUIRED)

find_package(box2d REQUIRED)
find_package(yaml-cpp REQUIRED)


add_executable(${PROJECT_NAME} Application.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    VulkanRenderer::VulkanRenderer
)
