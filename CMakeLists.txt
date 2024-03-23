cmake_minimum_required(VERSION 3.22)

set(PROJECT_NAME VulkanRenderer)
set(CMAKE_CXX_STANDARD 20)

# For some reason in ubuntu this gives undefined __asan_init reference.
# add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

project(${PROJECT_NAME} VERSION 1.0)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "") # works (in creating the compile_commands.json file)

option(ENGINE_BUILD_UNIT_TESTS "Build the VulkanRenderer unit tests" ON)
option(ENGINE_BUILD_TESTBED "Build the VulkanRenderer testbed" ON)
option(ENGINE_BUILD_DOCS "Build the VulkanRenderer documentation" OFF)
option(ENGINE_USER_SETTINGS "Override VulkanRenderer settings with VulkanRendererUserSettings.h" OFF)

option(BUILD_SHARED_LIBS "Build Box2D as a shared library" OFF)

include(GNUInstallDirs)
include_directories(
	${PROJECT_SOURCE_DIR}/VulkanRenderer
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

message("Message = ${CMAKE_INSTALL_PREFIX}")

# add_subdirectory(Sandbox)
add_subdirectory(src)
# add_subdirectory(Sandbox-Internal)


# set(PRECOMPILED_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>")
# set(INSTALLED_PRECOMPILED_PATH "${CMAKE_INSTALL_PREFIX}/include/Engine3DLinux/Engine3DLinuxPrecompiledHeader.h>")

# if(EXISTS ${INSTALLED_PRECOMPILED_PATH})
# 	set(PATH ${INSTALLED_PRECOMPILED_PATH})
# elseif(EXISTS ${PRECOMPILED_PATH})
# 	set(PATH ${PRECOMPILED_PATH})
# endif()


# target_precompile_headers(${PROJECT_NAME} PUBLIC
# 	"$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/include/Engine3D/Engine3DPrecompiledHeader.h>"
# )

target_precompile_headers(${PROJECT_NAME} PUBLIC
	"$<$<COMPILE_LANGUAGE:CXX>:>"
)

install(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/VulkanRenderer"
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

# Installing to /usr/local/public/GameEngine/
# install(
#   DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/assets"
#   DESTINATION "${CMAKE_INSTALL_LIBDIR}/GameEngine"
# )
