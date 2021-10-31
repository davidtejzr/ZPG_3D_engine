#include "SuziFlatObject.h"

SuziFlatObject::SuziFlatObject(Shader* shader, Model* model)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
}

void SuziFlatObject::loopObject(Camera* camera)
{
	_shader->useShader();
	_shader->modelToShader(_trans->getModel());
	_shader->projectionToShader(camera->getProjection());
	_shader->viewToShader(camera->getView());
	_model->modelInLoop();
	glDrawArrays(GL_TRIANGLES, 0, 2880);
}
