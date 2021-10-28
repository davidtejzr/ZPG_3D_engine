#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Scene.h"

class Init
{
public:
	Init();
	GLFWwindow* getWindow();
private:
	GLFWwindow* _window;
	int _width;
	int _height;
	static void error_callback(int error, const char* description);
};

