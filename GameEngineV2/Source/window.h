#pragma once
#include <iostream>
#include <string>
#include "glad/glad.h"
#include <glfw3.h>

class Window
{
private:
	int _width;
	int _height;
	std::string _title;
	GLFWwindow* _window;

public:
	Window(int width, int height, std::string title);
	int getWidth();
	int getHeight();
	std::string getTitle();

	int open();
	bool gameLoop();
};