#include "Bezier.h"

Bezier::Bezier(glm::mat4x3 B, float initRotate)
{
	_M = glm::mat4(1.0f);
	_A = glm::mat4(glm::vec4(-1.0, 3.0, -3.0, 1.0), glm::vec4(3.0, -6.0, 3.0, 0), glm::vec4(-3.0, 3.0, 0, 0), glm::vec4(1, 0, 0, 0));
	_B = B;
	_t = 0.5f;
	_delta = 0.003f;
	_initRotate = initRotate;
}

void Bezier::renderBezier(Tranformations* transformations)
{
	glm::vec4 parameters = glm::vec4(_t * _t * _t, _t * _t, _t, 1.0f);
	glm::vec3 p = parameters * _A * glm::transpose(_B);

	transformations->staticTranslate(p.x, p.y, p.z);
	if(_delta > 0)
		transformations->rotate(0.0f, _initRotate + 0.0f, 0.0f);
	else
		transformations->rotate(0.0f, _initRotate - 180.0f, 0.0f);


	if (_t >= 1.0f || _t <= 0.0f)
	{
		_delta *= -1;
	}

	_t += _delta;
}
