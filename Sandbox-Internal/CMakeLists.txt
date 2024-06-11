set(PROJECT_NAME Sandbox)

project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 20)

include_directories(
    ../3DEngine
    ../3DEngine/Core
)

add_executable(${PROJECT_NAME} Application.cpp)

target_link_libraries(
    ${PROJECT_NAME} PUBLIC
    3DEngine
    glfw
    # ${Vulkan_LIBRARIES}
    fmt
    spdlog
    glm
    tobanteGaming::Box2D
    yaml-cpp
    imgui
    ImGuizmo
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR})