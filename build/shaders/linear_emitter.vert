#version 150

in vec3 position;
in vec3 colour;
in vec3 velocity;
in float delay;
in float lifetime;

uniform float time;
uniform mat4 mvp;

out vec3 fColor0;

void main(void)
{
    if (time > delay) {
        float actual_time = mod(((time*1e-4) - delay), lifetime);
        vec3 new_pos = position + velocity * actual_time;
        gl_Position = mvp * vec4(new_pos, 1.0);
        fColor0 = colour;
    }
}
