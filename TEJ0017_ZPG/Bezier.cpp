#include "Bezier.h"

Bezier::Bezier(glm::mat4 A, glm::mat4x3 B, float t, float delta)
{
	_M = glm::mat4(1.0f);
	_A = A;
	_B = B;
	_t = t;
	_delta = delta;
}

void Bezier::renderBezier(Tranformations* transformations)
{
	glm::vec4 parameters = glm::vec4(_t * _t * _t, _t * _t, _t, 1.0f);
	glm::vec3 p = parameters * _A * glm::transpose(_B);

	transformations->staticTranslate(p.x, p.y, p.z);

	if (_t >= 1.0f || _t <= 0.0f)
	{
		_delta *= -1;
	}
	_t += _delta;
}
