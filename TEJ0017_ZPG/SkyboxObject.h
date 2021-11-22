#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

class SkyboxObject : public Object
{
public:
	SkyboxObject(Shader* shader, Model* model);
	void loopObject(Camera* camera);
};

