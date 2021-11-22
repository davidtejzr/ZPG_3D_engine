#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class UniversalTriangleObject : public Object
{
public:
	UniversalTriangleObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

