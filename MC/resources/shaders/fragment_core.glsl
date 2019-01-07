#version 440

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;

uniform sampler2D texture0;
uniform sampler2D texture1;
uniform vec3 light_pos0;
uniform vec3 camera_pos;

void main() {
	//fs_color = vec4(vs_color, 1.f);

	// Ambient light
	vec3 ambient_light = vec3(0.1f, 0.1f, 0.1f);

	// Diffuse light
	vec3 posToLightDirVec = normalize(vs_position - light_pos0);
	vec3 diffuse_color = vec3(1.f, 1.f, 1.f);
	float diffuse = clamp(dot(posToLightDirVec, vs_normal), 0, 1);
	vec3 diffuse_final = diffuse_color * diffuse;

	// specular light
	vec3 lightToPos = normalize(light_pos0 - vs_position);
	vec3 reflectDirVec = normalize(reflect(lightToPos, normalize(vs_normal)));
	vec3 posToView = normalize(vs_position - camera_pos);
	float specular_const = pow(max(dot(posToView, reflectDirVec), 0), 30);
	vec3 specularFinal = vec3(1.f, 1.f, 1.f) * specular_const;

	// attenuation light

	// final light

	fs_color = vec4(vs_color, 1.f) * texture(texture0, vs_texcoord)
		* (vec4(ambient_light, 1.f) + vec4(diffuse_final, 1.f))
		+ vec4(specularFinal, 1.f);
	//fs_color += texture(texture1, vs_texcoord);
	

}