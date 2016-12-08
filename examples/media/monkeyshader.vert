#version 130

in vec3 position;
in vec3 normals;
in vec2 texCoords;

out vec3 Normal;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
	vec4 nor = model * vec4(normals.xyz, 1.0f);
	Normal = nor.xyz;
	TexCoord = texCoords;
	gl_Position = projection * view * model * vec4(position, 1.0f);
}