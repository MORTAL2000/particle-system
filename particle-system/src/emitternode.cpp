#include "emitternode.h"

EmitterNode::EmitterNode(RenderFramework* framework)
    : ModelNode(framework, NULL)
{
    Shader *emitShader = new Shader("linear_emitter");

    map<string, BufferAttribute> attributes = framework->getShaderManager()->getDefaultAttributes();

    attributes.insert(pair<string, BufferAttribute>("velocity", VELOCITY_BUFFER));
    attributes.insert(pair<string, BufferAttribute>("delay", DELAY_BUFFER));

    emitShader->init(attributes);

    framework->getShaderManager()->addShader(emitShader);

    this->mesh = new Mesh(emitShader, GL_POINTS);
}

EmitterNode::~EmitterNode()
{

}

void EmitterNode::init()
{
    // TODO : create buffer data
}

void EmitterNode::sendUniforms(Shader *material)
{
    // TODO : change lifetime as an attribute for vertex bufffer computed in cpu with a certain variance
    static const float lifetime = 0.5f;
    framework->getShaderManager()->getShader("linear_emitter")->sendUniform("lifetime", lifetime);
}

void EmitterNode::preRender()
{
    glEnable(GL_PROGRAM_POINT_SIZE);
    glEnable(GL_BLEND);
}

void EmitterNode::postRender()
{
    glDisable(GL_PROGRAM_POINT_SIZE);
    glDisable(GL_BLEND);
}
