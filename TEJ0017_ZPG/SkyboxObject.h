#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"
#include "TextureManager.h"

class SkyboxObject : public Object
{
public:
	SkyboxObject(Shader* shader, Model* model, Texture* texture);
	void loopObject(Camera* camera);
};
