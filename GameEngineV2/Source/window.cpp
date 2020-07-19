#include "window.h"

Window::Window(int width, int height, std::string title): 
	_width(width), _height(height), _title(title)
{
	_window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);
}

inline int Window::getHeight()
{
	return _height;
}

inline int Window::getWidth()
{
	return _width;
}

inline std::string Window::getTitle()
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

	return 0;
}

bool Window::gameLoop()
{
	/* Render here */
	glClear(GL_COLOR_BUFFER_BIT);

	/* Swap front and back buffers */
	glfwSwapBuffers(_window);

	/* Poll for and process events */
	glfwPollEvents();

	return glfwWindowShouldClose(_window);
}