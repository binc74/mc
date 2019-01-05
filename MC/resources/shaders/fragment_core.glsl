#version 440

struct Matrial {
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	sampler2D diffuse_tex;
	sampler2D specular_tex;
};

in vec3 vs_position;
in vec3 vs_color;
in vec2 vs_texcoord;
in vec3 vs_normal;

out vec4 fs_color;

uniform Material material;

uniform sampler2D texture0;
uniform sampler2D texture1;
uniform vec3 light_pos0;
uniform vec3 camera_pos;

vec3 calculate_diffuse(Material material, vec3 vs_position, vec3 vs_normal, vec3 light_pos0) {
	vec3 posToLightDirVec = normalize(light_pos0 - vs_position);
	vec3 diffuse_color = vec3(1.f, 1.f, 1.f);
	float diffuse = clamp(dot(posToLightDirVec, vs_normal), 0, 1);

	return material.diffuse * diffuse;
}

vec3 calculate_specular(Material material, vec3 vs_position, vec3 vs_normal, vec3 light_pos0,
	vec3 camera_pos) {
	vec3 lightToPos = normalize(vs_position - light_pos0);
	vec3 reflectDirVec = normalize(reflect(lightToPos, normalize(vs_normal)));
	vec3 posToView = normalize(camera_pos - vs_position);
	float specular_const = pow(max(dot(posToView, reflectDirVec), 0), 30);

	return material.specular * specular_const;
}

void main() {
	//fs_color = vec4(vs_color, 1.f);

	// Ambient light
	vec3 ambient_light = material.ambient;

	// Diffuse light
	vec3 diffuse_light = calculate_diffuse(material, vs_position, vs_normal, light_pos0);

	// specular light	
	vec3 specular_light = calculate_specular(material, vs_position, vs_normal, light_pos0, camera_pos);

	// attenuation light

	// final light

	fs_color = vec4(vs_color, 1.f) * texture(material.diffuse_tex, vs_texcoord)
		* (vec4(ambient_light, 1.f) + vec4(diffuse_light, 1.f))
		+ vec4(specular_light, 1.f);
	//fs_color += texture(texture1, vs_texcoord);
	

}