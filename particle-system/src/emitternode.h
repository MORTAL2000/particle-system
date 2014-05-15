#ifndef EMITTERNODE_H
#define EMITTERNODE_H

#include "modelnode.h"

struct EmitterVertexData {
    Vec3 pos;
    Vec3 color;
    // TODO : add other attributes
};

class EmitterNode : public ModelNode
{
	public:
        EmitterNode(RenderFramework* framework);

		/**
		 * Compute default attributes of his mesh's shader
		 */
		void init();

		/**
		 * Send all of his "uniforms" to his own mesh's shader
		 */
		void sendUniforms(Shader* material);
};

#endif // EMITTERNODE_H
