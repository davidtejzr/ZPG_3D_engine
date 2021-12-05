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
    _count++;
}

Object* ObjectManager::getObject(int id)
{
    try
    {
        return _objects->at(id);
    }
    catch (const std::exception&)
    {

    }

    return nullptr;
}

void ObjectManager::removeObject(int id)
{
    _objects->erase(_objects->begin() + id);
    _count--;
}

int ObjectManager::getCount()
{
    return _count;
}
