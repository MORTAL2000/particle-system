#ifndef MODELNODE_H
#define MODELNODE_H

#include "scenenode.h"
#include "renderframework.h"

class ModelNode : public SceneNode
{
private:
    RenderFramework *framework;
public:
    ModelNode(RenderFramework* framework);

    void visit();
};

#endif // MODELNODE_H
