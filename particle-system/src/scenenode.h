#ifndef SCENENODE_H
#define SCENENODE_H

#include "math/matrix4.h"

class SceneNode
{
public:
    SceneNode();

    Matrix4 getTransform() const;
};

#endif // SCENENODE_H
