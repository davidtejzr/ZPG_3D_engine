#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include the standard C++ headers  
#include <iostream>
#include <vector>

#include "Light.h"
#include "Pointlight.h"
#include "Spotlight.h"

struct light
{
	glm::vec3 _position;
	glm::vec3 _color;
};

class LightManager
{
public:
	LightManager();
	void insertLight(Light light);
	Light getLight(int id);
private:
	std::vector<Light>* _lights;
};

