#include "Texture.h"

Texture::Texture()
{
	//glActiveTexture specifies whitch texture unit to make active
	glActiveTexture(GL_TEXTURE0);

	//Load texture and generate textureID
	GLuint textureID = SOIL_load_OGL_texture("Textures/test.png", SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glGenerateMipmap(GL_TEXTURE_2D);
}
