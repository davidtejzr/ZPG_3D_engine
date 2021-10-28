#version 330
out vec3 frag_colour; 
in vec3 color; 
void main ()
{ 
	frag_colour = color;
} 