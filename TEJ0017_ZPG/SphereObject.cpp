#include "SphereObject.h"

SphereObject::SphereObject(Shader* shader, Model* model)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
}

SphereObject::SphereObject(Shader* shader, Model* model, glm::vec3 color)
{
	_shader = shader;
	_model = model;
	_trans = new Tranformations();
	_color = color;
}

void SphereObject::loopObject(Camera* camera)
{
	_shader->useShader();
	_shader->modelToShader(_trans->getModel());
	_shader->projectionToShader(camera->getProjection());
	_shader->viewToShader(camera->getView());
	_shader->colorToShader(_color);
	_model->modelInLoop();
	glDrawArrays(GL_TRIANGLES, 0, 2904);
}
