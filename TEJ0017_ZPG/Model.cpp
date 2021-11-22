#include "Model.h"

Model::Model(int mode, const float* points, int pointsSize)
{
	//vertex buffer Model (VBO)
	_VBO = 0;
	glGenBuffers(1, &_VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, _VBO);
	glBufferData(GL_ARRAY_BUFFER, pointsSize, points, GL_STATIC_DRAW);

	//Vertex Array Model (VAO)
	_VAO = 0;
	glGenVertexArrays(1, &_VAO); //generate the VAO
	glBindVertexArray(_VAO); //bind the VAO

	glEnableVertexAttribArray(0); //enable vertex attributes
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO);

	if (mode == 0)
	{
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(points[0]), (GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(points[0]), (GLvoid*)(3 * sizeof(GL_FLOAT)));
	}
	else if (mode == 1)
	{
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(points[0]), (GLvoid*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(points[0]), (GLvoid*)(3 * sizeof(GL_FLOAT)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(points[0]), (GLvoid*)(6 * sizeof(GL_FLOAT)));
	}
}

void Model::modelInLoop()
{
	glBindVertexArray(_VAO);
}
