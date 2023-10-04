cmake_minimum_required(VERSION 3.0.0)

# Project name
# VERSION => Is what we name This is the first relaese of the project so it is version 1
project(mvp VERSION 0.1.0)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)        # Don't build Documentation
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)       # Don't build Tests
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)    # Don't build Examples
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)           # Don't build Installation Information
set(GLFW_USE_HYBRID_HPG ON CACHE BOOL "" FORCE)     # Add variables to use High Performance Graphics Card if available
add_subdirectory(vendor/glfw)#Here we said there is a library but still unlinked to our project :( Refer to include_directories below
#Still we need to link the .exe with the library to be able to use it so refer to target_link_libraries Below


# Add glfw to includes to be recongnized in <>
include_directories(
    vendor/glfw/include
    vendor/glad/include
    vendor/glm
)


# For Craeting Bin and directing .exe to it 😎😎
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)


# Add Executable
# Since Glad has no CMakeLists.txt file it has only .c file so add this .c with Executable list 🙄
add_executable(mvp main.cpp vendor/glad/src/gl.c)
target_link_libraries(mvp glfw)#Link mvp.exe with libraries (glfw)😉