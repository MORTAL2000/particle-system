#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "scenenode.h"

using namespace std;

class Scene
{
    vector<SceneNode*> nodes;
public:
    Scene();

    // TODO : add / removal / camera

    vector<SceneNode*>::iterator begin();
    vector<SceneNode*>::iterator end();
};

#endif // SCENE_H
