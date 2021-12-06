#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"
#include "TextureManager.h"

class UniversalTriangleObject : public Object
{
public:
	UniversalTriangleObject(Shader* shader, Model* model, Texture* texture);
	UniversalTriangleObject(Shader* shader, Model* model, Texture* texture, Texture* normalTexture);
	UniversalTriangleObject(Shader* shader, Model* model, Texture* texture, Bezier* bezier);
	void loopObject(Camera* camera);
};

