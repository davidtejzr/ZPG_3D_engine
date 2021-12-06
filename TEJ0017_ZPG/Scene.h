#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>

#include "ShaderManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Camera.h"
#include "Controller.h"
#include "TextureManager.h"
#include "LightManager.h"

//My models
#include "sphere.h"
#include "suzi_flat.h"
#include "suzi_smooth.h"
#include "tree.h"
#include "ground.h"
#include "plain.h"
#include "skybox.h"

static void newResolutions_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Camera::getInstance()->setWindowResolutions(width, height);
	printf("W: %d H: %d\n", width, height);
}

class Scene
{
public:
	virtual void renderScene() = 0;
protected:
	GLFWwindow* _window;
	ObjectManager* _objectManager;
	ShaderManager* _shaderManager;
	Camera* _camera;
	Controller* _controller;
	glm::vec3 _lightPosition = glm::vec3(10.0f, 10.0f, 10.0f);
};

