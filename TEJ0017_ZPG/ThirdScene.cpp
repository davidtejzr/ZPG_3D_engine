#include "ThirdScene.h"

ThirdScene::ThirdScene(GLFWwindow* window)
{
	_window = window;
	_objectManager = ObjectManager::getInstance();


	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	//3 - Blinn
	_shaderManager = ShaderManager::getInstance();

	//Texture textures;
	_textures = new TextureManager();
	_lights = new LightManager();

	//Lights initialization
	_lights->insertLight(glm::vec3(5.0f, 15.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f));

	Model* model0 = new Model("Objects/plane.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model0, _shaderManager->getShader(0), _textures->getTexture(3)));
	_objectManager->getObject(0)->getTransformations()->scale(35.0f, 35.0f, 35.0f);

	Model* model1 = new Model("Objects/skydome.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model1, _shaderManager->getShader(0), _textures->getTexture(0)));
	_objectManager->getObject(1)->getTransformations()->scale(5.0f, 5.0f, 5.0f);

	Model* model2 = new Model("Objects/building.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model2, _shaderManager->getShader(2), _textures->getTexture(1)));
	_objectManager->getObject(2)->getTransformations()->translate(-15.0f, 0.0f, 5.0f);

	for (int i = 0; i < 5; i++)
	{
		Model* model = new Model("Objects/tree.obj");
		_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model, _shaderManager->getShader(2), _textures->getTexture(2)));
		_objectManager->getObject(i + 3)->getTransformations()->translate((1.0f + (i * 5)), 0.0f, 0.0f);
		_objectManager->getObject(i + 3)->getTransformations()->scale(0.2f, 0.2f, 0.2f);
	}

	_camera = Camera::getInstance(_window, glm::vec3(0.0f, 1.5f, 4.0f));
	_controller = Controller::getInstance(_camera);
	_lightPosition = glm::vec3(10.0f, 10.0f, 10.0f);
}

void ThirdScene::renderScene()
{
	_controller->checkInputs();
	_camera->lookAt();
	//_shaderManager->getShader(3)->cameraPosToShader(_camera->getPosition());
	_shaderManager->getShader(3)->update();

	_shaderManager->getShader(2)->lightToShader("lights[0].position", _lights->getLight(0)._position);
	_shaderManager->getShader(2)->lightToShader("lights[0].color", _lights->getLight(0)._color);

	_shaderManager->getShader(2)->lightsCountToShader(1);
	//_shaderManager->getShader(3)->lightPosToShader(_lightPosition);

	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		_objectManager->getObject(i)->loopObject(_camera);
	}
}

