#include "Application.h"

Application* Application::_instance = nullptr;

Application* Application::getInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Application();
	}

	return _instance;
}

Application::Application()
{
	_init = Init::getInstance();
	_window = _init->getWindow();

	//ToDo
	//1. projit kod a zjistit, co by se dalo rozclenit na tridy/potomky
	//2. trida pro svetlo - potomci pro kontretni svetlo, zmena pro stisku L
	//3. callback pro zmenu okna a kontroler

	//Prepinani scen
	//FirstScene - moje scena
	//SecondScene - 4 kulicky
	//ThirdScene - SkyDome + Building + Trees
	//FourthScene - SkyBox + Terrain + Building + Trees

	//_scene = SceneFactory::initFirstScene(_window);
	//_scene = SceneFactory::initSecondScene(_window);
	//_scene = SceneFactory::initThirdScene(_window);
	_scene = SceneFactory::initFourthScene(_window);

	while (!glfwWindowShouldClose(_window))
	{
		// clear color and depth buffer
		//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		_scene->renderScene();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(_window);
	}

	glfwDestroyWindow(_window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
