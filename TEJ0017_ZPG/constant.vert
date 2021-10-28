#version 330  
layout(location=0) in vec3 _position;  
layout(location=1) in vec3 _color;  

uniform mat4 model;  
uniform mat4 view;  
uniform mat4 projection;  
out vec3 color;  

void main ()
{  
	gl_Position = projection * view * model * vec4(_position, 1.0); 
	color = _color;  
} 