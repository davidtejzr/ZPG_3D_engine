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
#include "Tranformations.h"

class Bezier
{
public:
	Bezier(glm::mat4 A, glm::mat4x3 B, float t, float delta);
	void renderBezier(Tranformations* transformations);
private:
	glm::mat4 _M;
	glm::mat4 _A;
	glm::mat4x3 _B;
	float _t;
	float _delta;
};

