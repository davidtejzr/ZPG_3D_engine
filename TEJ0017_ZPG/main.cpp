#include "Init.h"

//Tovarna (tovarna vytvori a v vramci jedne metody bude vykreslovat) -> objekt (zpracuje model, transformace, shader) -> model (vraci VAO)

int main(void)
{
	Init init;
	GLFWwindow* window = init.getWindow();
	Scene scene(window);

	while (!glfwWindowShouldClose(window))
	{
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		scene.renderScene();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}