#pragma once
#include "Init.h"

class Application
{
public:
	static Application* getInstance();
private:
	Application();
	static Application* _instance;
	Init* _init;
	GLFWwindow* _window;
};

