#ifndef MESH_H
#define MESH_H

#include "gl3.h"
#include "shader.h"
#include "bufferattributes.h"

class Mesh
{
private:
    Shader* material;
    GLuint vao;
    GLuint vbo[BUFFER_COUNT];

public:
    Mesh(Shader* material);
    ~Mesh();

    Shader* getMaterial();
    void draw();
    void createBufferData();
};

#endif // MESH_H
