#pragma once
#include "Scene.h"
#include "FirstScene.h"
#include "SecondScene.h"
#include "ThirdScene.h"

class SceneFactory
{
public:
	static Scene* initFirstScene(GLFWwindow* window);
	static Scene* initSecondScene(GLFWwindow* window);
	static Scene* initThirdScene(GLFWwindow* window);
};

