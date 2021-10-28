#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class SphereObject : public Object
{
public:
	SphereObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};