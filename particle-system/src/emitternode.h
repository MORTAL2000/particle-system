#ifndef EMITTERNODE_H
#define EMITTERNODE_H

#include "modelnode.h"

struct EmitterVertexData {
    Vec3 pos;
    Vec3 color;
    float delay;
    float velocity;
    // TODO : add other attributes
};

class EmitterNode : public ModelNode
{
    public:
        EmitterNode(RenderFramework* framework);
        ~EmitterNode();

        /**
         * Compute default attributes of his mesh's shader
         */
        void init();

        /**
         * Send all of his "uniforms" to his own mesh's shader
         */
        void sendUniforms(Shader* material);
        void preRender();
        void postRender();

};

#endif // EMITTERNODE_H
