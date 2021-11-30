#version 330
layout(location=0) in vec3 _position;  

uniform mat4 model;  
uniform mat4 view;  
uniform mat4 projection;  

void main ()
{  
	gl_Position = projection * view * model * vec4(_position, 1.0); 
} 