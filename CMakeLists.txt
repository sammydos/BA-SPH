cmake_minimum_required(VERSION 3.29.2)



project(BA-SPH CXX C)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PRJ_DIR ${CMAKE_CURRENT_SOURCE_DIR})

SET( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


include(FetchContent)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
glfw
GIT_REPOSITORY https://github.com/glfw/glfw.git
GIT_TAG 3.3.8
)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

set(GLAD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/glad)
set(GLM_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/glm)

set(SOURCES 
src/main.cpp
${GLAD_DIR}/src/glad.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/src
${GLAD_DIR}/include
${GLM_DIR}

)

target_link_libraries(${PROJECT_NAME} PRIVATE
	glfw
	OpenGL::GL
)

add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/shaders
	$<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders

)
