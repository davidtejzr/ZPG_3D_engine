#pragma once

//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Scene.h"
#include "SceneFactory.h"

static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Controller::getInstance(Camera::getInstance())->checkKeyboardInputs();
}

static void window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

static void window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

static void window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
	Camera::getInstance()->setWindowResolutions(width, height);
}

static void cursor_callback(GLFWwindow* window, double x, double y)
{
	Controller::getInstance(Camera::getInstance())->checkMouseCursor();
}

static void button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (TextureManager::getInstanceValue() != nullptr)
		Controller::getInstance(Camera::getInstance())->checkMouseIdentification();
}

class Init
{
public:
	static Init* getInstance();
	GLFWwindow* getWindow();
private:
	Init();
	static Init* _instance;
	GLFWwindow* _window;
	int _width;
	int _height;
	static void error_callback(int error, const char* description);
};

