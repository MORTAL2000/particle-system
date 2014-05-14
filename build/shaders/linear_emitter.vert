#version 150

uniform float time;
uniform float lifetime;

in float delay;
in vec3 position;
in vec3 velocity;

uniform mat4 MVP;
in vec3 color;
out vec3 fColor0;

void main(void)
{
	if (time > delay) {
		float actual_time = (time - delay) % lifetime;
		vec3 new_pos = position + velocity * actual_time;
		gl_Position = MVP * vec4(new_pos, 1.0);
		fColor0 = color;
	}
}
