#version 400
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;

out vec4 ex_worldPosition;
out vec4 ex_worldNormal;

uniform mat4 model, view, projection;

void main(void)
{
	gl_Position =  projection * view * model * vec4(position, 1.0);
	ex_worldPosition = model * vec4(position, 1.0);
	ex_worldNormal =  normalize(transpose (inverse((model))) * vec4(normal, 1.0));
}