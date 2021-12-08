#version 400

in vec4 ex_worldPosition;
in vec4 ex_worldNormal;
in vec2 _uv;
in mat3 tbn;
out vec4 frag_colour;

#define MAX_LIGHTS 4

struct pointlight
{
	vec3 position;
	vec3 diffuse;
	vec3 specular;
	vec3 color;
};

struct spotlight
{
	vec3 position;
	vec3 direction;
	float cutOff;
	float outerCutOff;
	vec3 color;
};

uniform vec3 cameraPosition;
uniform vec3 lightPosition;
uniform sampler2D textureUnitID;
uniform pointlight pointlights[MAX_LIGHTS];
uniform spotlight spotlight1;
uniform int lightsCount;
uniform int intensity = 1;

vec4 calcPointLight(vec3 l_position, vec3 l_color, vec3 cameraDirection, vec4 ambient)
{
	vec3 lightVector = normalize(l_position - vec3(ex_worldPosition));
	float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
	vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);
	vec3 reflectDirection = reflect((-normalize(l_position)), normalize(vec3(ex_worldNormal)));
	vec4 specular = pow(max(dot(cameraDirection, reflectDirection), 0.0f), 8) * vec4(0.5f);

	float distance = length(l_position - vec3(ex_worldPosition));
	float linear = 0.0045f;
	float quadratic = 0.0016f;

	float attenuation = 1.0 / (1.0f + linear * distance + quadratic * (distance * distance));  
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return ((ambient * vec4(l_color, 1.0)) + (diffuse * vec4(l_color, 1.0)) + (specular * vec4(l_color, 1.0)));
}

vec4 calcSpotLight(spotlight l_spotlight, vec3 cameraDirection, vec4 ambient)
{
	vec3 lightVector = normalize(l_spotlight.position - vec3(ex_worldPosition));
	float theta = dot(lightVector, normalize(-l_spotlight.direction));
	float epsilon = l_spotlight.cutOff - l_spotlight.outerCutOff;
	float intensity = clamp((theta - l_spotlight.outerCutOff) / epsilon, 0.0, 1.0); 

	if(theta > l_spotlight.outerCutOff)
	{
		float dotProduct = max(dot(lightVector, normalize(vec3(ex_worldNormal))), 0.0);
		vec4 diffuse = dotProduct * vec4(0.385, 0.647, 0.812, 1.0);
		vec3 reflectDirection = reflect((-normalize(l_spotlight.position)), normalize(vec3(ex_worldNormal)));
		vec4 specular = pow(max(dot(cameraDirection, reflectDirection), 0.0f), 8) * vec4(0.5f);

		diffuse *= intensity;
		specular *= intensity;

		return ((ambient * vec4(l_spotlight.color, 1.0)) + (diffuse * vec4(l_spotlight.color, 1.0)) + (specular * vec4(l_spotlight.color, 1.0)));
	}
	else
	{
		return ambient;
	}
}


void main(void)
{
	vec4 ambient = vec4(0.1);
	vec3 cameraDirection = normalize(cameraPosition - vec3(ex_worldPosition));
	vec4 result = vec4(0.0);

	result = calcSpotLight(spotlight1, cameraDirection, ambient);

	for(int i = 0; i < lightsCount; i++)
	{
		result += calcPointLight(pointlights[i].position, pointlights[i].color, cameraDirection, ambient);
	}

	frag_colour += result * texture(textureUnitID, _uv);
}