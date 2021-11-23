#include "ObjectFactory.h"

Object* ObjectFactory::initSphere(Model* model, Shader* shader)
{
    Object* object = new SphereObject(shader, model);
    return object;
}

Object* ObjectFactory::initTree(Model* model, Shader* shader)
{
    Object* object = new TreeObject(shader, model);
    return object;
}

Object* ObjectFactory::initSuziFlat(Model* model, Shader* shader)
{
    Object* object = new SuziFlatObject(shader, model);
    return object;
}

Object* ObjectFactory::initSuziSmooth(Model* model, Shader* shader)
{
    Object* object = new TreeObject(shader, model);
    return object;
}

Object* ObjectFactory::initGround(Model* model, Shader* shader)
{
    Object* object = new GroundObject(shader, model);
    return object;
}

Object* ObjectFactory::initPlain(Model* model, Shader* shader)
{
    Object* object = new PlainObject(shader, model);
    return object;
}

Object* ObjectFactory::initUniversalTriangle(Model* model, Shader* shader, Texture* texture)
{
    Object* object = new UniversalTriangleObject(shader, model, texture);
    return object;
}

Object* ObjectFactory::initSkybox(Model* model, Shader* shader, Texture* texture)
{
    Object* object = new SkyboxObject(shader, model, texture);
    return object;
}
