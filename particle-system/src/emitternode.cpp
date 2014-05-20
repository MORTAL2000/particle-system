#include "emitternode.h"

EmitterNode::EmitterNode(RenderFramework* framework)
    : ModelNode(framework, new Mesh(framework->getShaderManager()->getShader("default"), GL_LINES))
{
}

EmitterNode::~EmitterNode()
{

}

void EmitterNode::init()
{
    int dataSize = 6;
    EmitterVertexData* vertexData = new EmitterVertexData[dataSize];

    for(int i = 0; i < 3; ++i) {
        float m = i%3;
        Vec3 p1, p2(m==0, m==1, m==2);
        vertexData[2*i].pos = p1;
        vertexData[2*i].color = p2;
        vertexData[2*i+1].pos = p2;
        vertexData[2*i+1].color = p2;
    }

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
