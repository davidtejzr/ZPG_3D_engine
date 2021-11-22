#pragma once
//Include GLEW
#include <GL/glew.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

//Include Assimp
#include <assimp/Importer.hpp> // C++ importer interface
#include <assimp/scene.h> // aiScene output data structure
#include <assimp/postprocess.h> // Post processing flags

//Include the standard C++ headers  
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>

struct Vertex
{
	float Position[3];
	float Normal[3];
	float Texture[2];
	float Tangent[3];
};

//Mode:
//0 - 3x vrchol + 3x normala (nebo RGB)
//1 - 3x vrchol + 3x normala + 2x uv souradnice
//2 - 3x vrchol

class Model
{
public:
	Model(int mode, const float* points, int pointsSize);
	Model(std::string fileName);
	void modelInLoop();
	int getIndiciesCount();
protected:
	GLuint _VAO;
	GLuint _VBO;
	int _indicesCount;
};