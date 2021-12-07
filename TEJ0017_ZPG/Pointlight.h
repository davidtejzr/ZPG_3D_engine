#pragma once
#include "Light.h"

class Pointlight : public Light
{
public:
	Pointlight(glm::vec3 position, glm::vec3 color);
};

