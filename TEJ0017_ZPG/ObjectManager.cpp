#include "ObjectManager.h"

ObjectManager* ObjectManager::_instance = nullptr;

ObjectManager::ObjectManager()
{
    _objects = new std::vector<Object*>();
}

ObjectManager* ObjectManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new ObjectManager();
    }

    return _instance;
}

void ObjectManager::insertObject(Object* object)
{
    _objects->push_back(object);
}

Object* ObjectManager::getObject(int id)
{
    return _objects->at(id);
}
