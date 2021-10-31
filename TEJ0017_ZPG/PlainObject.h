#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class PlainObject : public Object
{
public:
	PlainObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

