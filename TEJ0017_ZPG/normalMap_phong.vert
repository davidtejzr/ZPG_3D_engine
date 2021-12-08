#version 400
layout(location = 0) in vec3 position;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 uv;
layout(location = 3) in vec3 tangent;

out vec4 ex_worldPosition;
out vec4 ex_worldNormal;
out vec2 _uv;
out mat3 tbn;

uniform mat4 model, view, projection;

void main(void)
{
	gl_Position =  projection * view * model * vec4(position, 1.0);
	ex_worldPosition = model * vec4(position, 1.0);
	ex_worldNormal =  normalize(transpose (inverse((model))) * vec4(normal, 1.0));
	mat3 normalMat = transpose(inverse(mat3(model)));

	//Gram–Schmidt orthonormalization
    vec3 _normal = normalize(normal);
    vec3 _tangent = normalize(tangent);
    _tangent = normalize(_tangent - dot(_tangent, _normal) * _normal);
    vec3 _bitangent = cross(_normal, _tangent);

	//TBN Matrix
	vec3 T = normalize(vec3(normalMat * _tangent));
    vec3 B = normalize(vec3(normalMat * _bitangent));
    vec3 N = normalize(vec3(normalMat * _normal));
    tbn = mat3(T, B, N);
	
	_uv = uv;
}