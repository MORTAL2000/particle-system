#include "renderer.h"

Renderer::Renderer()
{
}

void Renderer::pushMatrix(const Matrix4& mat)
{
    stack.push(mat);
}

void Renderer::popMatrix()
{
    stack.pop();
}

Matrix4 Renderer::getMVP() const
{
    return Matrix4::identity();
}

float Renderer::getTime() const {
    return 0;
}

void Renderer::render(float time) {
    pushMatrix(Matrix4::identity());

    // TODO
    // computeViewProjectionMatrix();
    // mat4 vp = camera.getViewMatrix * camera.getProjectionMatrix();
    // pushMatrix(vp);
    // for each node of scene
    //     node.visit();
    // end

    popMatrix();
}
