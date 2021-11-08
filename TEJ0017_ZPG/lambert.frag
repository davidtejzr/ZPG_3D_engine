#version 400
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 frag_colour;

uniform vec3 lightPosition;

void main(void)
{
	vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));
	float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
	vec4 ambient = vec4(0.1, 0.1, 0.1, 1.0);
	vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);
	frag_colour = ambient + diffuse;
}