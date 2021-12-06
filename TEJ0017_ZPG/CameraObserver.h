#pragma once
#include "ShaderManager.h"

class CameraObserver
{
public:
	CameraObserver();
	void notify();
private:
	ShaderManager* _shaderManager;
};