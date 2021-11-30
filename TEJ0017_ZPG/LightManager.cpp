#include "LightManager.h"

LightManager::LightManager()
{
    _lights = new std::vector<light>();
}

void LightManager::insertLight(glm::vec3 position, glm::vec3 color)
{   
    light l;
    l._position = position;
    l._color = color;
    _lights->push_back(l);
}

light LightManager::getLight(int id)
{
    return _lights->at(id);
}
