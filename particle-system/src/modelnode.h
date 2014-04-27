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
    Vec3 scale;
    Matrix4 getScalingMatrix() const;

protected:
    virtual void sendUniforms() = 0;
    void sendDefaultUniforms();

public:
    ModelNode(RenderFramework *framework, Mesh *mesh);
    ModelNode(RenderFramework* framework, Mesh* mesh, Vec3 position, Quaternion orientation);

    void setVisible(bool visible);
    void addChild(ModelNode *child);
    void visit();
    void setScale(const Vec3& scale);
    Matrix4 getTransform() const;
};

#endif // MODELNODE_H
