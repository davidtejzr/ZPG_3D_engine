#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class GroundObject : public Object
{
public:
	GroundObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

