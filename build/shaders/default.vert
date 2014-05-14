in vec3 position;
in vec3 colour;

uniform mat4 MVP;

void main(void)
{
    gl_Position = MVP * vec4(position, 1.0);
}
