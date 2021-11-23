#version 330

out vec4 frag_colour; 
in vec3 color; 
in vec2 uv;
in vec3 position;
uniform samplerCube textureUnitID;

void main ()
{ 
	//frag_colour = color;
	frag_colour = texture(textureUnitID, position);
} 