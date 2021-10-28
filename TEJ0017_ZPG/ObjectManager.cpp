#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
    _objects = new std::vector<Object*>();
}

void ObjectManager::insertObject(Object* object)
{
    _objects->push_back(object);
}

Object* ObjectManager::getObject(int id)
{
    return _objects->at(id);
}
