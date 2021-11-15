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

class Camera
{
public:
	static Camera* getInstance(GLFWwindow* window, glm::vec3 position);
	void lookAt();
	glm::mat4 getView();
	glm::mat4 getProjection();
	glm::vec3 getPosition();

	GLFWwindow* _window;
	glm::vec3 _position;
	glm::vec3 _orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);
	int _width = 0;
	int _height = 0;

private:
	Camera(GLFWwindow* window, glm::vec3 position);
	static Camera* _instance;
	glm::mat4 _view = glm::mat4(1.0f);
	glm::mat4 _projection = glm::mat4(1.0f);
};

