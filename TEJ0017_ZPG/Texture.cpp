#include "Texture.h"

Texture::Texture(const char* fileName, int id)
{
	_id = id;
	_texture = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

Texture::Texture(const char* xpos, const char* xneg, const char* ypos, const char* yneg, const char* zpos, const char* zneg, int id)
{
	_id = id;
	_texture = SOIL_load_OGL_cubemap(xpos, xneg, ypos, yneg, zpos, zneg, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS);
}

int Texture::getId()
{
	return _id;
}

void Texture::setTexture()
{
	//glActiveTexture specifies whitch texture unit to make active
	glActiveTexture(GL_TEXTURE0 + _id);

	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Texture::setTextureCubemap()
{
	//glActiveTexture specifies whitch texture unit to make active
	glActiveTexture(GL_TEXTURE0 + _id);

	glBindTexture(GL_TEXTURE_CUBE_MAP, _texture);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	//glGenerateMipmap(GL_TEXTURE_CUBE_MAP);
}
