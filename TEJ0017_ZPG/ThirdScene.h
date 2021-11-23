#pragma once
#include "Scene.h"

class ThirdScene : public Scene
{
public:
	ThirdScene(GLFWwindow* window);
	void renderScene();
private:
	TextureManager* _textures;
};

