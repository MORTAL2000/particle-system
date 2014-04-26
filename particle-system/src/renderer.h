#ifndef RENDERER_H
#define RENDERER_H

#include "renderframework.h"
#include "matrixstack.h"
#include "scene.h"
#include "modelnode.h"

class Renderer : public RenderFramework
{
private:
    MatrixStack<Matrix4> stack;
    Scene *scene;
public:
    Renderer(Scene* scene);
    ~Renderer();

    void pushMatrix(const Matrix4& mat);
    void popMatrix();
    Matrix4 getMVP() const;
    float getTime() const;
    void render(float time);
};

#endif // RENDERER_H
