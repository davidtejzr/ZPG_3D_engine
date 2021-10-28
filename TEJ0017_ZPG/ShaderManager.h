#pragma once
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "Shader.h"

class ShaderManager
{
public:
	ShaderManager();
	Shader* getShader(int id);
private:
	std::vector<Shader>* _shaders;
};

