#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class TreeObject : public Object
{
public:
	TreeObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

