#pragma once
//Include GLEW
#include <GL/glew.h>

class Model
{
public:
	Model(const float* points, int pointsSize);
	void modelInLoop();
protected:
	GLuint _VAO;
	GLuint _VBO;
};