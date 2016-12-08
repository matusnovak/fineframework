#version 130

in vec3 Normal;
in vec2 TexCoord;

uniform sampler2D sampler;
uniform int mode;

const vec3 lightDir = vec3(0.0f, 0.0f, 1.0f);

void main() {
	if(mode == 0){
		gl_FragColor = vec4(Normal, 1.0f);
	} else if(mode == 1){
		gl_FragColor = texture(sampler, TexCoord);
	} else if(mode == 2){
		float d = dot(Normal, lightDir);
		vec4 color = texture(sampler, TexCoord) * d;
		color.a = 1.0f;
		gl_FragColor = color;
	} else {
		gl_FragColor = vec4(1.0f);
	}
}