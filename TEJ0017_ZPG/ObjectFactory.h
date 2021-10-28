#pragma once
#include "Shader.h"
#include "Model.h"
#include "Tranformations.h"
#include "Object.h"

#include "SphereObject.h"
#include "TreeObject.h"
#include "SuziFlatObject.h"
#include "SuziSmoothObject.h"
#include "GroundObject.h"

class ObjectFactory
{
public:
	static Object* initSphere(Model* model, Shader* shader);
	static Object* initTree(Model* model, Shader* shader);
	static Object* initSuziFlat(Model* model, Shader* shader);
	static Object* initSuziSmooth(Model* model, Shader* shader);
	static Object* initGround(Model* model, Shader* shader);
};

