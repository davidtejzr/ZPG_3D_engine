#include "UniversalTriangleObject.h"

UniversalTriangleObject::UniversalTriangleObject(Shader* shader, Model* model)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
}

void UniversalTriangleObject::loopObject(Camera* camera)
{
	_shader->useShader();
	_shader->modelToShader(_trans->getModel());
	_shader->projectionToShader(camera->getProjection());
	_shader->viewToShader(camera->getView());
	_model->modelInLoop();
	glDrawElements(GL_TRIANGLES, _model->getIndiciesCount(), GL_UNSIGNED_INT, NULL);
}
