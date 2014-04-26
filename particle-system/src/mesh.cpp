#include "mesh.h"

Mesh::Mesh(Shader* material)
{
    this->material = material;
    for(int i = 0; i < BUFFER_COUNT; ++i) {
        vbo[i] = 0;
    }

    glGenVertexArrays(1, &vao);
}

Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(BUFFER_COUNT, vbo);
}

Shader* Mesh::getMaterial()
{
    return material;
}

void Mesh::draw() {
    glBindVertexArray(vao);

    // TODO : draw call

    glBindVertexArray(0);
}

void Mesh::createBufferData()
{
    glBindVertexArray(vao);

    // TODO : create buffer data

    glBindVertexArray(0);
}
