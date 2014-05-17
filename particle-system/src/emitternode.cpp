#include "emitternode.h"

EmitterNode::EmitterNode(RenderFramework* framework)
    : ModelNode(framework, new Mesh(framework->getShaderManager()->getShader("default"), GL_TRIANGLES))
{

}

EmitterNode::~EmitterNode()
{

}

void EmitterNode::init()
{
    int dataSize = 3;
    EmitterVertexData* vertexData = new EmitterVertexData[dataSize];

    vertexData[0].pos = Vec3(-1.0, 0.0, -3.0);
    vertexData[0].color = Vec3(1.0, 0.0, 0.0);
    vertexData[1].pos = Vec3( 0.0, 1.0, -3.0);
    vertexData[1].color = Vec3(0.0, 1.0, 0.0);
    vertexData[2].pos = Vec3( 1.0, 0.0, -3.0);
    vertexData[2].color = Vec3(0.0, 0.0, 1.0);

    vector<VertexBufferDataInfo> dataInfos;

    VertexBufferDataInfo colorInfo;
    colorInfo.attributeType = COLOUR_BUFFER;
    colorInfo.stride = 6 * sizeof(float);
    colorInfo.offset = 3 * sizeof(float);
    colorInfo.dataType = GL_FLOAT;
    colorInfo.size = 3;

    dataInfos.push_back(colorInfo);

    VertexBufferDataInfo posInfo;
    posInfo.attributeType = VERTEX_BUFFER;
    posInfo.stride = 6 * sizeof(float);
    posInfo.offset = 0;
    posInfo.dataType = GL_FLOAT;
    posInfo.size = 3;

    dataInfos.push_back(posInfo);

    mesh->createInterleavedBufferData(dataInfos, vertexData, dataSize * sizeof(EmitterVertexData), GL_STATIC_DRAW);

    delete vertexData;
}

void EmitterNode::sendUniforms(Shader *material)
{
    // TODO : send default uniforms relative to the buffer data
}
