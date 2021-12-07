#include "Spotlight.h"

Spotlight::Spotlight(glm::vec3 position, glm::vec3 color, glm::vec3 direction, float cutOff, float outerCutOff)
{
	_position = position;
	_color = color;
	_direction = direction;
	_cutOff = cutOff;
	_outerCutOff = outerCutOff;
}

glm::vec3 Spotlight::getDirection()
{
	return _direction;
}

float Spotlight::getCutOff()
{
	return _cutOff;
}

float Spotlight::getOuterCutOff()
{
	return _outerCutOff;
}
