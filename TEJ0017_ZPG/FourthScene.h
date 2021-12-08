#pragma once
#include "Scene.h"

class FourthScene : public Scene
{
public:
	FourthScene(GLFWwindow* window);
	void renderScene();
	void lightInit(int shaderId);
private:
	TextureManager* _textures;
	LightManager* _lights;
};

