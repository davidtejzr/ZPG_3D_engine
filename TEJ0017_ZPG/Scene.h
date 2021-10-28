#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>

#include "ShaderManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Camera.h"

//My models
#include "sphere.h"
#include "suzi_flat.h"
#include "suzi_smooth.h"
#include "tree.h"
#include "ground.h"

class Scene
{
public:
	Scene(GLFWwindow* window);
	void renderScene();
private:
	GLFWwindow* _window;
	class ObjectManager* _objectManager;
	class Camera* _camera;
};

