#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Camera.h"
#include "Texture.h"

class Object
{
public:
	virtual void loopObject(Camera* camera) = 0;
	Tranformations* getTransformations();
protected:
	Shader* _shader;
	Model* _model;
	Tranformations* _trans;
	Texture* _texture;
};

