#include "LightManager.h"

LightManager::LightManager()
{
    _lights = new std::vector<Light>();
}

void LightManager::insertLight(Light light)
{
    _lights->push_back(light);
}

Light LightManager::getLight(int id)
{
    return _lights->at(id);
}
