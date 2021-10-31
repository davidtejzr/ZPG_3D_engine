#include "SphereObject.h"

SphereObject::SphereObject(Shader* shader, Model* model)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
}

void SphereObject::loopObject(Camera* camera)
{
	_shader->useShader();
	_shader->modelToShader(_trans->getModel());
	_shader->projectionToShader(camera->getProjection());
	_shader->viewToShader(camera->getView());
	_shader->cameraPosToShader(camera->getPosition());
	_model->modelInLoop();
	glDrawArrays(GL_TRIANGLES, 0, 2904);
}
