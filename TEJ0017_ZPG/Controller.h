#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Camera.h"

class Controller
{
public:
	static Controller* getInstance(Camera* camera);
	void checkInputs();
private:
	Controller(Camera* camera);
	static Controller* _instance;
	Camera* _camera;
	float _speed = 0.1f;
	float _sensitivity = 100.0f;
	bool _firstClick = true;
};

