#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"
#include "TextureManager.h"

class TerrainObject : public Object
{
public:
	TerrainObject(Shader* shader, Model* model, Texture* texture);
	void loopObject(Camera* camera);
};

