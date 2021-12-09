#include "Tranformations.h"

Tranformations::Tranformations()
{
	_model = glm::mat4(1.0f);
}

void Tranformations::rotate(float x, float y, float z)
{
	_model = glm::rotate(_model, glm::radians(x), glm::vec3(1, 0, 0));
	_model = glm::rotate(_model, glm::radians(y), glm::vec3(0, 1, 0));
	_model = glm::rotate(_model, glm::radians(z), glm::vec3(0, 0, 1));
}

void Tranformations::translate(float x, float y, float z)
{
	_model = glm::translate(_model, glm::vec3(x, y, z));
}

void Tranformations::scale(float x, float y, float z)
{
	_scaleVec = glm::vec3(x, y, z);
	_model = glm::scale(_model, glm::vec3(x, y, z));
}

void Tranformations::staticTranslate(float x, float y, float z)
{
	_model = glm::translate(glm::vec3(x, y, z));
}

void Tranformations::setModel(glm::mat4 model)
{
	_model = model;
}

glm::mat4 Tranformations::getModel()
{
	return _model;
}

glm::vec3 Tranformations::getScaleVec()
{
	return _scaleVec;
}
