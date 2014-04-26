#ifndef RENDERER_H
#define RENDERER_H

#include "renderframework.h"
#include "matrixstack.h"

class Renderer : public RenderFramework
{
private:
    MatrixStack<Matrix4> stack;
public:
    Renderer();

    void pushMatrix(const Matrix4& mat);
    void popMatrix();
    Matrix4 getMVP() const;
    float getTime() const;
    void render(float time);
};

#endif // RENDERER_H
