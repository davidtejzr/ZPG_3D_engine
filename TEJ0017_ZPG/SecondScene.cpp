#include "SecondScene.h"

SecondScene::SecondScene(GLFWwindow* window)
{
	_window = window;
	_objectManager = ObjectManager::getInstance();

	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	_shaderManager = ShaderManager::getInstance();

	Model* model0 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model0, _shaderManager->getShader(2)));
	_objectManager->getObject(0)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(0)->getTransformations()->translate(-2.5f, 0.0f, 0.0f);

	Model* model1 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model1, _shaderManager->getShader(2)));
	_objectManager->getObject(1)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(1)->getTransformations()->translate(0.0f, 2.5f, 0.0f);

	Model* model2 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model2, _shaderManager->getShader(2)));
	_objectManager->getObject(2)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(2)->getTransformations()->translate(2.5f, 0.0f, 0.0f);

	Model* model3 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model3, _shaderManager->getShader(2)));
	_objectManager->getObject(3)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(3)->getTransformations()->translate(0.0f, -2.5f, 0.0f);

	_camera = Camera::getInstance(_window, glm::vec3(0.0f, 0.0f, 6.0f));
	_controller = Controller::getInstance(_camera);
}

void SecondScene::renderScene()
{
	_controller->checkInputs();
	_camera->lookAt();

	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		_objectManager->getObject(i)->loopObject(_camera);
	}
}
