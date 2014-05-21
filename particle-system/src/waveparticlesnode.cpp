#include "waveparticlesnode.h"

WaveParticlesNode::WaveParticlesNode(RenderFramework* framework)
    : ModelNode(framework, NULL)
{
    Shader *wavesShader = new Shader("waves");

    map<string, BufferAttribute> attributes = framework->getShaderManager()->getDefaultAttributes();

    wavesShader->init(attributes);

    framework->getShaderManager()->addShader(wavesShader);

    this->mesh = new Mesh(wavesShader, GL_POINTS);
}

WaveParticlesNode::~WaveParticlesNode()
{

}

void WaveParticlesNode::init()
{

}

void WaveParticlesNode::sendUniforms(Shader* material)
{

}

void WaveParticlesNode::preRender()
{

}

void WaveParticlesNode::postRender()
{

}
