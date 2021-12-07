#pragma once
#include "Light.h"

class Spotlight : public Light
{
public:
	Spotlight(glm::vec3 position, glm::vec3 color, glm::vec3 direction, float cutOff, float outerCutOff);
	glm::vec3 getDirection();
	float getCutOff();
	float getOuterCutOff();
private:
	glm::vec3 _direction;
	float _cutOff;
	float _outerCutOff;
};

