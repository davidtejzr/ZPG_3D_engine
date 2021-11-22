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
#include "PlainObject.h"
#include "SkyboxObject.h"
#include "UniversalTriangleObject.h"

class ObjectFactory
{
public:
	static Object* initSphere(Model* model, Shader* shader);
	static Object* initTree(Model* model, Shader* shader);
	static Object* initSuziFlat(Model* model, Shader* shader);
	static Object* initSuziSmooth(Model* model, Shader* shader);
	static Object* initGround(Model* model, Shader* shader);
	static Object* initPlain(Model* model, Shader* shader);
	static Object* initSkybox(Model* model, Shader* shader);
	static Object* initUniversalTriangle(Model* model, Shader* shader);
};

