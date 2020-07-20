#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "glad/glad.h"
#include <glfw3.h>

class Shaders
{
private:
	std::string _vertexFilePath;
	std::string _fragmentFilePath;

public:
	Shaders(std::string vertexFilePath, std::string fragmentFilePath);
	GLuint LoadShaders();
};

