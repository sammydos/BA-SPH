#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


int main(int argc, char** argv) {

	if (!glfwInit()) { std::cerr << "no glfw" << std::endl;
	return -1;
	}

	std::cout << "glfw" << std::endl;

	glfwTerminate();
	return 0;


}