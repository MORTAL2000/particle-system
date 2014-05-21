#version 150

in vec3 position;
in vec3 colour;
in vec2 offset;

uniform mat4 mvp;
uniform float time;
uniform int width;

out vec3 fColour;

float waveAmplitude = 2.0;
float waveFreq = 1e-5f;

void main(void)
{
    gl_Position = mvp * vec4(position, 1.0);

    float xy = (offset.x * offset.y) / width;
    gl_Position.y += waveAmplitude * cos(time * waveFreq * xy);
    fColour = colour;
}
