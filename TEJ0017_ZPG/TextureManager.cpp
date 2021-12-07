#include "TextureManager.h"

TextureManager* TextureManager::_instance = nullptr;

TextureManager::TextureManager()
{
	_textures = new std::vector<Texture>();

	_textures->push_back(Texture("Textures/skydome.png", 0));
	_textures->push_back(Texture("Textures/building.png", 1));
	_textures->push_back(Texture("Textures/tree.png", 2));
	_textures->push_back(Texture("Textures/test.png", 3));
	_textures->push_back(Texture("Textures/grass.png", 4));
	_textures->push_back(Texture("Textures/cubemap/posx.jpg", "Textures/cubemap/negx.jpg", "Textures/cubemap/posy.jpg", "Textures/cubemap/negy.jpg", "Textures/cubemap/posz.jpg", "Textures/cubemap/negz.jpg", 5));
	_textures->push_back(Texture("Textures/zombie.png", 6));
	_textures->push_back(Texture("Textures/albedo.png", 7));
	_textures->push_back(Texture("Textures/normalmap.png", 8));
}

TextureManager* TextureManager::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new TextureManager();
	}

	return _instance;
}

TextureManager* TextureManager::getInstanceValue()
{
	return _instance;
}

Texture* TextureManager::getTexture(int id)
{
	return &_textures->at(id);
}
