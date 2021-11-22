#pragma once
#include "Scene.h"
#include "FirstScene.h"
#include "SecondScene.h"

class SceneFactory
{
public:
	static Scene* initFirstScene(GLFWwindow* window);
	static Scene* initSecondScene(GLFWwindow* window);
};

