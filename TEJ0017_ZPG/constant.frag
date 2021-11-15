#version 330

out vec4 frag_colour; 
in vec3 color; 
in vec2 uv;
uniform sampler2D textureUnitID;

void main ()
{ 
	//frag_colour = color;
	//frag_colour = vec4(uv, 1.0, 1.0);
	frag_colour = texture(textureUnitID, uv);
} 