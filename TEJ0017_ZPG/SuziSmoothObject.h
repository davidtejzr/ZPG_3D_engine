#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class SuziSmoothObject : Object
{
public:
	SuziSmoothObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

