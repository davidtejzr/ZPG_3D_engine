#version 400
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
layout(location = 3) in vec3 tangent;

out vec4 ex_worldPosition;
out vec4 ex_worldNormal;
out vec2 _uv;

uniform mat4 model, view, projection;

void main(void)
{
	gl_Position =  projection * view * model * vec4(position, 1.0);
	ex_worldPosition = model * vec4(position, 1.0);
	ex_worldNormal =  normalize(transpose (inverse((model))) * vec4(normal, 1.0));
	
	_uv = uv;
}