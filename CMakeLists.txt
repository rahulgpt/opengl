cmake_minimum_required(VERSION 3.24.0)

project(opengl)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES src/main.cpp)

add_subdirectory(src/external/glfw)

add_executable(app ${SOURCE_FILES})

find_package(GLEW REQUIRED)

if(GLEW_FOUND)
    message("GLEW Found")
    include_directories(${GLEW_INCLUDE_DIRS})
    target_link_libraries(app GLEW::GLEW)
elseif(NOT GLEW_FOUND)
    message(FATAL_ERROR "GLEW Not Found")
endif()

target_link_libraries(app glfw)

