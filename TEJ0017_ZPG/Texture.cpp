#include "Texture.h"

Texture::Texture(const char* fileName, int id)
{
	_id = id;
	_texture = SOIL_load_OGL_texture(fileName, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	//textures->push_back(texture);
}

int Texture::getId()
{
	return _id;
}

void Texture::setTexture()
{
	//glActiveTexture specifies whitch texture unit to make active
	glActiveTexture(GL_TEXTURE0 + _id);

	//Load texture and generate textureID
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glGenerateMipmap(GL_TEXTURE_2D);
}
