#include "modelnode.h"

ModelNode::ModelNode(RenderFramework* framework, Mesh* mesh)
{
    this->mesh = mesh;
    this->framework = framework;
}

void ModelNode::sendDefaultUniforms()
{
    Shader *mat = mesh->getMaterial();

    mat->sendUniform("mvp", framework->getMVP());
    mat->sendUniform("time", framework->getTime());
}

Matrix4 ModelNode::getScalingMatrix() const
{
    return Matrix4::createScale(scale);
}

Matrix4 ModelNode::getTransform() const
{
    return getTranslationMatrix() * getRotationMatrix() * getScalingMatrix();
}

void ModelNode::setVisible(bool visible)
{
    this->visible = visible;
}

void ModelNode::addChild(ModelNode* child)
{
    children.push_back(child);
}

void ModelNode::visit()
{
    if(!visible)
        return;

    framework->pushMatrix(getTransform());

    vector<ModelNode*>::iterator it;
    for(it = children.begin(); it != children.end(); ++it) {
        (*it)->visit();
    }

    Shader *mat = mesh->getMaterial();

    // use current shader
    mat->use();

    // send the default uniforms
    sendDefaultUniforms();

    // inner send uniforms
    sendUniforms();

    // draw the mesh
    mesh->draw();

    // unuse current shader
    mat->release();

    framework->popMatrix();
}
