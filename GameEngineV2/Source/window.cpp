#include "window.h"

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

Window::Window(int width, int height, std::string title): 
	_width(width), _height(height), _title(title)
{
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL 

	_window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
}

int Window::getHeight()
{
	return _height;
}

int Window::getWidth()
{
	return _width;
}

std::string Window::getTitle()
{
	return _title;
}

int Window::open()
{
	if (!_window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(_window);

	// Set the required callback functions
	glfwSetKeyCallback(_window, key_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	// Define the viewport dimensions
	glViewport(0, 0, _width, _height);

	return 0;
}

bool Window::isClosing()
{
	// Swap the screen buffers
	glfwSwapBuffers(_window);

	return glfwWindowShouldClose(_window);
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}