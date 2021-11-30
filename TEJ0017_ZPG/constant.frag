#version 330

out vec4 frag_colour; 
in vec3 color; 
in vec2 uv;
in vec3 position;
uniform sampler2D textureUnitID;
//uniform samplerCube textureUnitID;

void main ()
{ 
	//frag_colour = color;
	//frag_colour = vec4(uv, 1.0, 1.0);


	frag_colour = texture(textureUnitID, uv);
	//frag_colour = texture(textureUnitID, position);
} 