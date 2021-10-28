#include "testObject.h"

void testObject::initObject()
{
	//_shaderManager = new ShaderManager();
	//_shaderManager->getShader(1);

	_model = new Model(sphere, sizeof(sphere));

	_transformations = new Tranformations();

	_transformations->scale(0.5f, 0.5f, 1.0f);
}

void testObject::loopObject(Shader* shader)
{
	_model->modelInLoop();
	glDrawArrays(GL_TRIANGLES, 0, 92814);
	_transformations->rotate(0.0f, -1.0f, 0.0f);
	shader->modelToShader(_transformations->getModel());
}
