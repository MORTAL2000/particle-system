#ifndef MESH_H
#define MESH_H

#include <vector>

#include "gl3.h"
#include "shader.h"
#include "bufferattribute.h"

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

struct VertexBufferDataInfo {
    BufferAttribute attributeType;
    GLsizei stride;
    int size;
    int offset;
};

class Mesh
{
private:
    Shader* material;
    GLuint vao;
    GLuint vbo;

public:
    Mesh(Shader* material);
    ~Mesh();

    Shader* getMaterial();
    void draw();
    void createInterleavedBufferData(const vector<VertexBufferDataInfo>& dataInfo,
                                     void* data, GLsizeiptr totalDataSize, GLenum usage);
};

#endif // MESH_H
