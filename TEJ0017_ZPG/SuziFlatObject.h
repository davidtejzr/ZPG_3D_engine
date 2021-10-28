#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class SuziFlatObject : public Object
{
public:
	SuziFlatObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

