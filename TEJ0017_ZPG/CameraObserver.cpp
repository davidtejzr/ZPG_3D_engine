#include "CameraObserver.h"

CameraObserver::CameraObserver()
{
	_shaderManager = ShaderManager::getInstance();
}

void CameraObserver::notify()
{
	for (int i = 0; i < _shaderManager->getCount(); i++)
	{
		_shaderManager->getShader(i)->update();
	}
}
