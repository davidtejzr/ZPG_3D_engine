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
uniform sampler2D normalTextureUnitID;
uniform pointlight pointlights[MAX_LIGHTS];
uniform spotlight spotlight1;
uniform int lightsCount;
uniform int intensity = 1;

vec4 calcPointLight(vec3 l_position, vec3 l_color, vec3 cameraDirection, vec4 ambient, vec3 normal)
{
	vec3 lightVector = normalize(l_position - vec3(ex_worldPosition));
	vec4 specular = vec4(0,0,0,0);
	vec4 diffuse = vec4(0,0,0,0);

	if( dot(normalize(lightVector), normalize(normal)) > 0)
	{	
		diffuse = max(dot(normalize(lightVector), normalize(normal)), 0.0) *  texture(textureUnitID, _uv); //vec4( 0.385, 0.647, 0.812, 1.0);
		vec3 reflectDirection = reflect(-normalize(lightVector),normalize(normal));
		specular = pow(max(dot(normalize(reflectDirection), normalize(cameraDirection)), 0.0), 32)  * vec4(1.0);
	}

	float distance = length(l_position - vec3(ex_worldPosition));
	float linear = 0.0045f;
	float quadratic = 0.0016f;

	float attenuation = 1.0 / (1.0f + linear * distance + quadratic * (distance * distance));  
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return ((ambient * vec4(l_color, 1.0)) + (diffuse * vec4(l_color, 1.0)) + (specular * vec4(l_color, 1.0)));
}

vec4 calcSpotLight(spotlight l_spotlight, vec3 cameraDirection, vec4 ambient, vec3 normal)
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

		if( dot(normalize(lightVector), normalize(normal)) > 0)
		{	
			diffuse = max(dot(normalize(lightVector), normalize(normal)), 0.0) *  texture(textureUnitID, _uv); //vec4( 0.385, 0.647, 0.812, 1.0);
			reflectDirection = reflect(-normalize(lightVector),normalize(normal));
			specular = pow(max(dot(normalize(reflectDirection), normalize(cameraDirection)), 0.0), 32)  * vec4(1.0);
		}

		diffuse *= intensity;
		specular *= intensity;

		return ((ambient * vec4(l_spotlight.color, 1.0)) + (diffuse * vec4(l_spotlight.color, 1.0)) + (specular * vec4(l_spotlight.color, 1.0)));
	}
	else
	{
		return ambient;
	}
}

float calcDiffuse(vec3 lightDir, vec3 normal)
{
	return max(dot(normalize(lightDir), normalize(normal)), 0.0);
}

float calcSpec(vec3 light, vec3 normal, float shininess)
{
	return  pow(max(dot(normalize(light), normalize(normal)), 0.0),shininess) ;
}

void main(void)
{
	/*vec3 encodedNormal  = texture(normalTextureUnitID, _uv).rgb;
	encodedNormal = 2.0 * encodedNormal - 1.0; //RGB to vector
	encodedNormal = normalize (encodedNormal*vec3(1,1,intensity)); 
	vec3 normal = normalize(tbn * encodedNormal);

	vec4 ambient = vec4(0.1);
	vec3 cameraDirection = normalize(cameraPosition - vec3(ex_worldPosition));
	vec4 result = vec4(0.0);

	result = calcSpotLight(spotlight1, cameraDirection, ambient, normal);

	for(int i = 0; i < lightsCount; i++)
	{
		result += calcPointLight(pointlights[i].position, pointlights[i].color, cameraDirection, ambient, normal);
	}

	frag_colour += result * texture(textureUnitID, _uv);*/




	 vec4 specular = vec4(0,0,0,0);
	 vec4 diffuse = vec4(0,0,0,0);
	 vec4 ambient = vec4( 0.1, 0.1, 0.1, 1.0);
	 
	 vec3 camPosition=vec3(0,0,-1);
	 vec3 lightPosition= vec3(10.0,0.0,-10.0); 

	 vec3 encodedNormal  = texture(normalTextureUnitID, _uv).rgb;
	 encodedNormal = 2.0 * encodedNormal - 1.0; //RGB to vector
	 encodedNormal = normalize (encodedNormal*vec3(1,1,intensity)); //intensity
	 vec3 normal = normalize(tbn * encodedNormal) ;
	
	 vec3 lightDirection = normalize(lightPosition - vec3(ex_worldPosition));
	 vec3 cameraDirection = normalize(camPosition - vec3(ex_worldPosition));

	 if( dot(normalize(lightDirection), normalize(normal)) > 0)
	 {
		diffuse = calcDiffuse(lightDirection, normal) *  texture(textureUnitID, _uv); //vec4( 0.385, 0.647, 0.812, 1.0);
		vec3 reflectDir= reflect(-normalize(lightDirection),normalize(normal));
		specular = calcSpec(reflectDir, cameraDirection, 32)  * vec4(1.0, 1.0, 1.0, 1.0);
	 }
    frag_colour = ambient + diffuse + specular;	 
}