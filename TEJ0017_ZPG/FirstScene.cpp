#include "FirstScene.h"

FirstScene::FirstScene(GLFWwindow* window)
{
	_window = window;
	_objectManager = ObjectManager::getInstance();

	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	_shaderManager = ShaderManager::getInstance();

	//Model* model0 = new Model(ground, sizeof(ground));
	//_objectManager->insertObject(ObjectFactory::initGround(model0, shaderManager.getShader(1)));

	Model* model0 = new Model(plain, sizeof(plain));
	_objectManager->insertObject(ObjectFactory::initPlain(model0, _shaderManager->getShader(1)));
	_objectManager->getObject(0)->getTransformations()->scale(6.0f, 0.0f, 6.0f);

	Model* model1 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model1, _shaderManager->getShader(2)));
	_objectManager->getObject(1)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(1)->getTransformations()->translate(-1.0f, 1.0f, -2.0f);

	Model* model2 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model2, _shaderManager->getShader(2)));
	_objectManager->getObject(2)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(2)->getTransformations()->translate(-1.0f, 3.0f, -2.0f);

	Model* model3 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model3, _shaderManager->getShader(2)));
	_objectManager->getObject(3)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(3)->getTransformations()->translate(1.0f, 1.0f, -2.0f);

	Model* model4 = new Model(sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(model4, _shaderManager->getShader(2)));
	_objectManager->getObject(4)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(4)->getTransformations()->translate(1.0f, 3.0f, -2.0f);

	Model* model5 = new Model(tree, sizeof(tree));
	_objectManager->insertObject(ObjectFactory::initTree(model5, _shaderManager->getShader(1)));
	_objectManager->getObject(5)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(5)->getTransformations()->translate(5.5f, 0.0f, 0.0f);

	Model* model6 = new Model(suziFlat, sizeof(suziFlat));
	_objectManager->insertObject(ObjectFactory::initSuziFlat(model6, _shaderManager->getShader(1)));
	_objectManager->getObject(6)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(6)->getTransformations()->translate(5.5f, 1.0f, 3.0f);

	Model* model7 = new Model(suziSmooth, sizeof(suziSmooth));
	_objectManager->insertObject(ObjectFactory::initSuziSmooth(model7, _shaderManager->getShader(1)));
	_objectManager->getObject(7)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(7)->getTransformations()->translate(2.5f, 1.0f, 5.0f);

	Model* model8 = new Model(tree, sizeof(tree));
	_objectManager->insertObject(ObjectFactory::initTree(model8, _shaderManager->getShader(0)));
	_objectManager->getObject(8)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(8)->getTransformations()->translate(5.5f, 0.0f, -6.0f);

	Model* model9 = new Model(tree, sizeof(tree));
	_objectManager->insertObject(ObjectFactory::initTree(model9, _shaderManager->getShader(1)));
	_objectManager->getObject(9)->getTransformations()->scale(0.5f, 0.5f, 0.5f);
	_objectManager->getObject(9)->getTransformations()->translate(8.5f, 0.0f, -2.5f);

	//_camera = new Camera(_window, glm::vec3(0.0f, 0.0f, 2.0f));
	_camera = Camera::getInstance(_window, glm::vec3(0.0f, 1.5f, 4.0f));
	_controller = Controller::getInstance(_camera);
	_shaderManager->getShader(1)->lightPosToShader(_lightPosition);
	_shaderManager->getShader(2)->lightPosToShader(_lightPosition);
}

void FirstScene::renderScene()
{
	_controller->checkInputs();
	_camera->lookAt();
	_shaderManager->getShader(2)->cameraPosToShader(_camera->getPosition());

	_objectManager->getObject(5)->getTransformations()->rotate(0.0f, 1.0f, 0.0f);
	_objectManager->getObject(6)->getTransformations()->rotate(0.0f, 1.0f, 0.0f);

	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		_objectManager->getObject(i)->loopObject(_camera);
	}
}
