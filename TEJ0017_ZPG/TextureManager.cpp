#include "TextureManager.h"

TextureManager* TextureManager::_instance = nullptr;

TextureManager::TextureManager()
{
    _textures = new std::vector<Texture*>();
}

TextureManager* TextureManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new TextureManager();
    }

    return _instance;
}

void TextureManager::insertTexture(Texture* texture)
{
    _textures->push_back(texture);
    _count++;
}

Texture* TextureManager::getTexture(int id)
{
    return _textures->at(id);
}

int TextureManager::getCount()
{
    return _count;
}
