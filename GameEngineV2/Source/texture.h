#pragma once
#include <string>
#include <iostream>
#include "glad/glad.h"
#include <glfw3.h>
#include <GLI/gli.hpp>

class Texture
{
private:
	std::string _filePath;

public:
	Texture(std::string filePath);
	GLuint loadTexture();
};