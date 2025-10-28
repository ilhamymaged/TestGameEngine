cmake_minimum_required(VERSION 3.10)
project("3D Game Engine")

# =========================
# GLFW setup (no extras)
# =========================
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/glfw)

# =========================
# Assimp setup (no extras)
# =========================
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_INSTALL OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_ZLIB ON CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)
add_subdirectory(thirdparty/assimp)

# =========================
# ImGui setup (manual build)
# =========================
# ImGui doesn’t use CMake by default, so you can build it manually
file(GLOB IMGUI_SRC
    thirdparty/imgui/*.cpp
    thirdparty/imgui/backends/imgui_impl_glfw.cpp
    thirdparty/imgui/backends/imgui_impl_opengl3.cpp
)
add_library(ImGui STATIC ${IMGUI_SRC})
target_include_directories(ImGui PUBLIC
    thirdparty/imgui
    thirdparty/imgui/backends
    thirdparty/glfw/include
)

# =========================
# Engine source
# =========================
file(GLOB_RECURSE SRC_FILES src/*.cpp)
list(APPEND SRC_FILES src/glad.c)
add_executable(CMakeTarget ${SRC_FILES})
target_include_directories(CMakeTarget PRIVATE include)

# =========================
# Link all libs
# =========================
target_link_libraries(CMakeTarget PRIVATE glfw ImGui assimp)

if (WIN32)
    target_link_libraries(CMakeTarget PRIVATE opengl32)
endif()