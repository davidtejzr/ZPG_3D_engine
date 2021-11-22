#pragma once
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Texture.h"

class TextureManager
{
public:
	static TextureManager* getInstance();
	void insertTexture(Texture* texture);
	Texture* getTexture(int id);
	int getCount();
private:
	TextureManager();
	static TextureManager* _instance;
	std::vector<Texture*>* _textures;
	int _count = 0;
};

