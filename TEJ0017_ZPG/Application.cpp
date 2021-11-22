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

	//Prepinani scen
	//FirstScene - moje scena
	//SecondScene - 4 kulicky

	Scene* scene = SceneFactory::initFirstScene(_window);
	//Scene* scene = SceneFactory::initSecondScene(_window);

	while (!glfwWindowShouldClose(_window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene->renderScene();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(_window);
	}

	glfwDestroyWindow(_window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
