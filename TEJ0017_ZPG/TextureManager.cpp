#include "TextureManager.h"

TextureManager::TextureManager()
{
	textures = new std::vector<GLuint>();
}

void TextureManager::loadTexture(const char* name)
{
	GLuint texture = SOIL_load_OGL_texture(name, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	textures->push_back(texture);
}

void TextureManager::setTexture(int id)
{
	//glActiveTexture specifies whitch texture unit to make active
	glActiveTexture(GL_TEXTURE0 + id);

	//Load texture and generate textureID
	glBindTexture(GL_TEXTURE_2D, textures->at(id));
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glGenerateMipmap(GL_TEXTURE_2D);
}
