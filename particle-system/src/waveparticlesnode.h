#ifndef WAVEPARTICLESNODE_H
#define WAVEPARTICLESNODE_H

#include "modelnode.h"

struct WaveParticlesVertexData {
    Vec3 pos;
    Vec3 color;
};

class WaveParticlesNode : ModelNode
{
public:
    WaveParticlesNode(RenderFramework* framework);
    ~WaveParticlesNode();

    void init();
    void sendUniforms(Shader* material);
    void preRender();
    void postRender();
};

#endif // WAVEPARTICLESNODE_H
