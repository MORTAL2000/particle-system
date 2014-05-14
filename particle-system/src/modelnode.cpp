#include "modelnode.h"

ModelNode::ModelNode(RenderFramework* framework, Mesh* mesh)
{
    this->visible = true;
    this->mesh = mesh;
    this->framework = framework;
    this->scale = Vec3(1.0f);
}

ModelNode::ModelNode(RenderFramework* framework, Mesh* mesh, Vec3 position, Quaternion orientation)
    : SceneNode(position, orientation)
{
    this->visible = true;
    this->mesh = mesh;
    this->framework = framework;
    this->scale = Vec3(1.0f);
}

void ModelNode::sendDefaultUniforms(Shader *material)
{
    material->sendUniform("mvp", framework->getMVP());
    material->sendUniform("time", framework->getTime());
}

Matrix4 ModelNode::getScalingMatrix()
{
    scalingMatrix = Matrix4::createScale(scale);
    return scalingMatrix;
}

Matrix4 ModelNode::getTransform()
{
    transform = getTranslationMatrix() * getRotationMatrix() * getScalingMatrix();
    return transform;
}

void ModelNode::setScale(const Vec3& scale)
{
    this->scale = scale;
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

    if(mat == NULL) {
        mat = framework->getShaderManager()->getShader("default");
    }

    // use current shader
    mat->use();

    // send the default uniforms
    sendDefaultUniforms(mat);

    // inner send uniforms
    sendUniforms(mat);

    // draw the mesh
    mesh->draw();

    // unuse current shader
    mat->release();

    framework->popMatrix();
}
