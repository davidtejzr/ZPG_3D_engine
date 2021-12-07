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
	_cameraObserver = new CameraObserver();
	_textures = TextureManager::getInstance();
	_lights = new LightManager();

	Model* model0 = new Model("Objects/skybox.obj");
	_objectManager->insertObject(ObjectFactory::initSkybox(model0, _shaderManager->getShader(4), _textures->getTexture(5)));
	_objectManager->getObject(nextObject)->getTransformations()->scale(10.0f, 10.0f, 10.0f);
	nextObject++;


	//Lights initialization
	_lights->insertLight(Pointlight(glm::vec3(5.0f, 15.0f, 3.0f), glm::vec3(1.0f, 1.0f, 1.0f)));
	_lights->insertLight(Pointlight(glm::vec3(-25.0f, 2.0f, 3.0f), glm::vec3(1.0f, 0.0f, 0.0f)));


	//Objects initialization
	Model* light1 = new Model(0, sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(light1, _shaderManager->getShader(5), _lights->getLight(0).getColor()));
	_objectManager->getObject(nextObject)->getTransformations()->translate(_lights->getLight(0).getPosition().x, _lights->getLight(0).getPosition().y, _lights->getLight(0).getPosition().z);
	nextObject++;

	Model* light2 = new Model(0, sphere, sizeof(sphere));
	_objectManager->insertObject(ObjectFactory::initSphere(light2, _shaderManager->getShader(5), _lights->getLight(1).getColor()));
	_objectManager->getObject(nextObject)->getTransformations()->translate(_lights->getLight(1).getPosition().x, _lights->getLight(1).getPosition().y, _lights->getLight(1).getPosition().z);
	nextObject++;

	Model* model1 = new Model("Objects/teren.obj");
	_objectManager->insertObject(ObjectFactory::initTerrain(model1, _shaderManager->getShader(2), _textures->getTexture(4)));
	nextObject++;

	Model* model2 = new Model("Objects/building.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model2, _shaderManager->getShader(2), _textures->getTexture(1)));
	_objectManager->getObject(nextObject)->getTransformations()->translate(-15.0f, 0.0f, 5.0f);
	nextObject++;

	Model* model3 = new Model("Objects/zombie.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model3, _shaderManager->getShader(2), _textures->getTexture(6), 
		new Bezier(glm::mat4x3(glm::vec3(-20, 0, 17), glm::vec3(0, 0, 20), glm::vec3(15, 0, 12), glm::vec3(30, 0, 10)), 90.0f)));
	nextObject++;

	Model* model4 = new Model("Objects/zombie.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model4, _shaderManager->getShader(2), _textures->getTexture(6),
		new Bezier(glm::mat4x3(glm::vec3(-3, 0, -5), glm::vec3(-3, 0, 5), glm::vec3(-3, 0, 10), glm::vec3(-3, 0, 15)), 0.0f)));
	nextObject++;

	Model* model5 = new Model("Objects/zombie.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model5, _shaderManager->getShader(2), _textures->getTexture(6),
		new Bezier(glm::mat4x3(glm::vec3(30, 0, -2), glm::vec3(15, 0, -3), glm::vec3(0, 0, -1), glm::vec3(-20, 0, -10)), -90.0f)));
	nextObject++;

	Model* model6 = new Model("Objects/normalSphere.obj");
	_objectManager->insertObject(ObjectFactory::initUniversalTriangle(model6, _shaderManager->getShader(2), _textures->getTexture(7), _textures->getTexture(8)));
	_objectManager->getObject(nextObject)->getTransformations()->translate(-5.0f, 40.0f, -5.0f);
	_objectManager->getObject(nextObject)->getTransformations()->scale(20.0f, 20.0f, 20.0f);
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
}

void FourthScene::renderScene()
{
	//_controller->checkInputsWithIdentification();
	_camera->lookAt();
	_cameraObserver->notify();

	_shaderManager->getShader(2)->lightToShader("pointlights[0].position", _lights->getLight(0).getPosition());
	_shaderManager->getShader(2)->lightToShader("pointlights[1].position", _lights->getLight(1).getPosition());
	_shaderManager->getShader(2)->lightToShader("pointlights[0].color", _lights->getLight(0).getColor());
	_shaderManager->getShader(2)->lightToShader("pointlights[1].color", _lights->getLight(1).getColor());

	//Spotlight - Key L
	Spotlight spotlight(_camera->getPosition(), glm::vec3(1.0, 1.0, 1.0), _camera->getOrientation(), 12.5f, 17.5f);
	if (_controller->getSpotlightStatus())
	{
		_shaderManager->getShader(2)->lightToShader("spotlight1.position", spotlight.getPosition());
		_shaderManager->getShader(2)->lightToShader("spotlight1.direction", spotlight.getDirection());
		_shaderManager->getShader(2)->lightToShaderFloat("spotlight1.cutOff", glm::cos(glm::radians(spotlight.getCutOff())));
		_shaderManager->getShader(2)->lightToShaderFloat("spotlight1.outerCutOff", glm::cos(glm::radians(spotlight.getOuterCutOff())));
		_shaderManager->getShader(2)->lightToShader("spotlight1.color", spotlight.getColor());
	}
	else
		_shaderManager->getShader(2)->lightToShaderFloat("spotlight1.outerCutOff", glm::cos(glm::radians(0.0f)));

	_shaderManager->getShader(2)->lightsCountToShader(2);

	//SkyBox motion
	_objectManager->getObject(0)->getTransformations()->staticTranslate(_camera->getPosition().x, _camera->getPosition().y, _camera->getPosition().z);

	// clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < _objectManager->getCount(); i++)
	{
		glStencilFunc(GL_ALWAYS, i, 0xFF);
		if(_objectManager->getObject(i) != nullptr)
			_objectManager->getObject(i)->loopObject(_camera);
	}
}
