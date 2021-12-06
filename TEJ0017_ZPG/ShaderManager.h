#pragma once
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Shader.h"

class ShaderManager
{
public:
	static ShaderManager* getInstance();
	Shader* getShader(int id);
	int getCount();
private:
	ShaderManager();
	static ShaderManager* _instance;
	std::vector<Shader>* _shaders;
	int _count = 0;
};

