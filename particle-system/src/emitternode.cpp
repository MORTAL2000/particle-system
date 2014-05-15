#include "emitternode.h"

EmitterNode::EmitterNode(RenderFramework* framework) : ModelNode(framework, NULL)
{

}

void EmitterNode::init()
{
    /* construct the mesh */
    Shader* mat = framework->getShaderManager()->getShader("default");

    this->mesh = new Mesh(mat, GL_POINTS);

    // TODO : create interleaved buffer data
}

void EmitterNode::sendUniforms(Shader *material)
{
    // TODO : send default uniforms relative to the buffer data
}
