#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Camera.h"
#include "Texture.h"
#include "Bezier.h"

class Object
{
public:
	virtual void loopObject(Camera* camera) = 0;
	Tranformations* getTransformations();
	void changeShader(Shader* shader);
protected:
	Shader* _shader;
	Model* _model;
	Tranformations* _trans;
	Texture* _texture;
	Texture* _normalTexture = nullptr;
	Bezier* _bezier = nullptr;
};

