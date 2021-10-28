#pragma once
#include "Init.h"

class testObject
{
private:
	class ShaderManager* _shaderManager;
	class Model* _model;
	class Tranformations* _transformations;
public:
	void initObject();
	void loopObject(Shader* shader);
};

