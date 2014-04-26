#ifndef MODELNODE_H
#define MODELNODE_H

#include <vector>
#include "scenenode.h"
#include "renderframework.h"
#include "mesh.h"

class ModelNode : public SceneNode
{
private:
    bool visible;
    Mesh *mesh;
    RenderFramework *framework;
    vector<ModelNode*> children;

public:
    ModelNode(RenderFramework* framework, Mesh* mesh);

    void setVisible(bool visible);
    virtual void sendUniforms() = 0;
    void sendDefaultUniforms();
    void addChild(ModelNode *child);
    void visit();
};

#endif // MODELNODE_H
