#pragma once
#include "Scene.h"

class FourthScene : public Scene
{
public:
	FourthScene(GLFWwindow* window);
	void renderScene();
private:
	TextureManager* _textures;
};

