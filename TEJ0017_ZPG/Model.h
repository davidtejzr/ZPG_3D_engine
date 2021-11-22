#pragma once
//Include GLEW
#include <GL/glew.h>

//Mode:
//0 - 3x vrchol + 3x normala (nebo RGB)
//1 - 3x vrchol + 3x normala + 2x uv souradnice

class Model
{
public:
	Model(int mode, const float* points, int pointsSize);
	void modelInLoop();
protected:
	GLuint _VAO;
	GLuint _VBO;
};