#include "FourthScene.h"

float x = 0.0f;
float z = 0.0f;
int nextObject = 0;

FourthScene::FourthScene(GLFWwindow* window)
{
	_window = window;
	_objectManager = ObjectManager::getInstance();


	//Prepinani shaderu
	//0 - Constant
	//1 - Lambert
	//2 - Phong
	//3 - Blinn
	//4 - Cubemap constant
	//5 - Light constant
	_shaderManager = ShaderManager::getInstance();

	//Texture textures;
	_textures = new TextureManager();
	_lights = new LightManager();

	//Lights initialization
	_lights->insertLight(glm::vec3(5.0f, 15.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	_lights->insertLight(glm::vec3(-25.0f, 2.0f, 3.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	//Objects initialization
	Model* light1 = new Model(0, sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(light1, _shaderManager->getShader(5), _lights->getLight(0)._color));
	_objectManager->getObject(nextObject)->getTransformations()->translate(_lights->getLight(0)._position.x, _lights->getLight(0)._position.y, _lights->getLight(0)._position.z);
	nextObject++;

	Model* light2 = new Model(0, sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(light2, _shaderManager->getShader(5), _lights->getLight(1)._color));
	_objectManager->getObject(nextObject)->getTransformations()->translate(_lights->getLight(1)._position.x, _lights->getLight(1)._position.y, _lights->getLight(1)._position.z);
	nextObject++;

	Model* model0 = new Model("Objects/teren.obj");
	_objectManager->insertObject(ObjectFactory::initTerrain(model0, _shaderManager->getShader(2), _textures->getTexture(4)));
	nextObject++;

	Model* model1 = new Model("Objects/skybox.obj");
	_objectManager->insertObject(ObjectFactory::initSkybox(model1, _shaderManager->getShader(4), _textures->getTexture(5)));
	_objectManager->getObject(nextObject)->getTransformations()->scale(100.0f, 100.0f, 100.0f);
	nextObject++;

	Model* model2 = new Model("Objects/building.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model2, _shaderManager->getShader(2), _textures->getTexture(1)));
	_objectManager->getObject(nextObject)->getTransformations()->translate(-15.0f, 0.0f, 5.0f);
	nextObject++;

	for (int j = 0; j < 5; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			Model* model = new Model("Objects/tree.obj");
			_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model, _shaderManager->getShader(2), _textures->getTexture(2)));
			_objectManager->getObject(nextObject)->getTransformations()->translate((1.0f + (i * 5)), 0.0f, (3.0f * j));
			_objectManager->getObject(nextObject)->getTransformations()->scale(0.2f, 0.2f, 0.2f);
			nextObject++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		Model* model = new Model("Objects/tree.obj");
		_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model, _shaderManager->getShader(2), _textures->getTexture(2)));
		_objectManager->getObject(nextObject)->getTransformations()->translate(-30.0f, 0.0f, (2.0f + (i * 5)));
		_objectManager->getObject(nextObject)->getTransformations()->scale(0.2f, 0.2f, 0.2f);
		nextObject++;
	}

	_camera = Camera::getInstance(_window, glm::vec3(0.0f, 1.5f, 4.0f));
	_controller = Controller::getInstance(_camera);
	_lightPosition = glm::vec3(10.0f, 10.0f, 10.0f);
}

void FourthScene::renderScene()
{
	_controller->checkInputs(_textures);
	_camera->lookAt();
	//_shaderManager->getShader(3)->cameraPosToShader(_camera->getPosition());
	_shaderManager->getShader(2)->update();

	_shaderManager->getShader(2)->lightToShader("lights[0].position", _lights->getLight(0)._position);
	_shaderManager->getShader(2)->lightToShader("lights[1].position", _lights->getLight(1)._position);
	_shaderManager->getShader(2)->lightToShader("lights[0].color", _lights->getLight(0)._color);
	_shaderManager->getShader(2)->lightToShader("lights[1].color", _lights->getLight(1)._color);

	_shaderManager->getShader(2)->lightsCountToShader(2);

	//SkyBox motion
	if (_camera->getPosition().x > x)
	{
		_objectManager->getObject(3)->getTransformations()->translate(0.001f, 0.0f, 0.0f);
		x = _camera->getPosition().x;
	}
	else if (_camera->getPosition().x < x)
	{
		_objectManager->getObject(3)->getTransformations()->translate(-0.001, 0.0f, 0.0f);
		x = _camera->getPosition().x;
	}

	if (_camera->getPosition().z > z)
	{
		_objectManager->getObject(3)->getTransformations()->translate(0.0f, 0.0f, 0.001f);
		z = _camera->getPosition().z;
	}
	else if (_camera->getPosition().z < z)
	{
		_objectManager->getObject(3)->getTransformations()->translate(0.0f, 0.0f, -0.001f);
		z = _camera->getPosition().z;
	}


	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		glStencilFunc(GL_ALWAYS, i, 0xFF);
		if(_objectManager->getObject(i) != nullptr)
			_objectManager->getObject(i)->loopObject(_camera);
	}
}