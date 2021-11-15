#version 400
in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
out vec4 frag_colour;

uniform vec3 cameraPosition;
uniform vec3 lightPosition;

void main(void)
{
	vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));

	float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
	vec4 ambient = vec4(0.1);
	vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);

	vec3 cameraDirection = normalize(cameraPosition - vec3(ex_worldPosition));
	vec3 reflectDirection = reflect((-normalize(lightVector)), normalize(vec3(ex_worldNormal)));
	float specular = pow(max(dot(normalize(lightVector + cameraDirection), vec3(ex_worldNormal)), 0.0), 32.0) * 0.5f;

	frag_colour = ambient + diffuse + specular;
}