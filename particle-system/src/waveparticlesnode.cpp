#include "waveparticlesnode.h"

WaveParticlesNode::WaveParticlesNode(RenderFramework* framework)
    : ModelNode(framework, NULL)
{
    Shader *wavesShader = new Shader("waves");

    map<string, BufferAttribute> attributes = framework->getShaderManager()->getDefaultAttributes();

    attributes.insert(pair<string, BufferAttribute>("offset", OFFSET_BUFFER));
    wavesShader->init(attributes);
    framework->getShaderManager()->addShader(wavesShader);

    this->mesh = new Mesh(wavesShader, GL_POINTS);
    this->areaWidth = 100;
}

WaveParticlesNode::~WaveParticlesNode()
{

}

void WaveParticlesNode::init()
{
    int nbParticles = areaWidth * areaWidth;

    WaveParticlesVertexData* waveBufferData = new WaveParticlesVertexData[nbParticles];

    float paddingx = 0.5f;
    float paddingz = 0.5f;

    for(int i = 0; i < areaWidth; ++i) {
        for(int j = 0; j < areaWidth; ++j) {
            float halfWidth = areaWidth / 4.0;

            float x = i * paddingx - halfWidth;
            float z = j * paddingz - halfWidth;

            waveBufferData[i*areaWidth + j].pos = Vec3(x, 0.0, z);
            waveBufferData[i*areaWidth + j].color = Vec3(1.0, 1.0, 1.0);
            waveBufferData[i*areaWidth + j].offset = Vec2(i, j);
        }
    }

    vector<VertexBufferDataInfo> dataInfos;

    int stride = sizeof(WaveParticlesVertexData);

    VertexBufferDataInfo colorInfo;
    colorInfo.attributeType = COLOUR_BUFFER;
    colorInfo.stride = stride;
    colorInfo.offset = sizeof(Vec3);
    colorInfo.dataType = GL_FLOAT;
    colorInfo.size = 3;

    dataInfos.push_back(colorInfo);

    VertexBufferDataInfo posInfo;
    posInfo.attributeType = VERTEX_BUFFER;
    posInfo.stride = stride;
    posInfo.offset = 0;
    posInfo.dataType = GL_FLOAT;
    posInfo.size = 3;

    dataInfos.push_back(posInfo);

    VertexBufferDataInfo offsetInfo;
    offsetInfo.attributeType = OFFSET_BUFFER;
    offsetInfo.stride = stride;
    offsetInfo.offset = 2 * sizeof(Vec3);
    offsetInfo.dataType = GL_FLOAT;
    offsetInfo.size = 2;

    dataInfos.push_back(offsetInfo);

    mesh->createInterleavedBufferData(dataInfos, waveBufferData, nbParticles * sizeof(WaveParticlesVertexData), GL_STATIC_DRAW);
}

void WaveParticlesNode::sendUniforms(Shader* material)
{
    material->sendUniform("width", areaWidth);
}

void WaveParticlesNode::preRender()
{

}

void WaveParticlesNode::postRender()
{

}
