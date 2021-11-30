#version 400

in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
in vec2 uv;
out vec4 frag_colour;

#define MAX_LIGHTS 4

struct light
{
	vec3 position;
	vec3 diffuse;
	vec3 specular;
	vec3 color;
};

uniform vec3 cameraPosition;
uniform vec3 lightPosition;
uniform sampler2D textureUnitID;
uniform light lights[MAX_LIGHTS];
uniform int lightsCount;


void main(void)
{
	vec4 ambient = vec4(0.1);
	vec3 cameraDirection = normalize(cameraPosition - vec3(ex_worldPosition));
	vec4 result = vec4(0.0);


	for(int i = 0; i < lightsCount; i++)
	{
		vec3 lightVector = normalize(lights[i].position - vec3(ex_worldPosition));
		float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
		vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);
		vec3 reflectDirection = reflect((-normalize(lights[i].position)), normalize(vec3(ex_worldNormal)));
		float specular = pow(max(dot(cameraDirection, reflectDirection), 0.0f), 8) * 0.5f;

		result += ((ambient * vec4(lights[i].color, 1.0)) + (diffuse * vec4(lights[i].color, 1.0)) + (specular * vec4(lights[i].color, 1.0)));
	}

	frag_colour = result * texture(textureUnitID, uv);



	//vec3 lightVector = normalize(lightPosition - vec3(ex_worldPosition));

	//float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
	//vec4 ambient = vec4(0.1);
	//vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);

	//vec3 cameraDirection = normalize(cameraPosition - vec3(ex_worldPosition));
	//vec3 reflectDirection = reflect((-normalize(lightVector)), normalize(vec3(ex_worldNormal)));
	//float specular = pow(max(dot(cameraDirection, reflectDirection), 0.0f), 8) * 0.5f;

	//frag_colour = (ambient + diffuse + specular) * texture(textureUnitID, uv);
}