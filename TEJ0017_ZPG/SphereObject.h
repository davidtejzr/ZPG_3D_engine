#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class SphereObject : public Object
{
public:
	SphereObject(Shader* shader, Model* model);
	SphereObject(Shader* shader, Model* model, glm::vec3 color);
	void loopObject(Camera* camera);
	glm::vec3 _color = glm::vec3(0.0f);
};