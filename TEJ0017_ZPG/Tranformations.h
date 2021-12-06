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

class Tranformations
{
public:
	Tranformations();

	void rotate(float x, float y, float z);
	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void staticTranslate(float x, float y, float z);
	void setModel(glm::mat4 model);
	glm::mat4 getModel();
private:
	glm::mat4 _model;
};

