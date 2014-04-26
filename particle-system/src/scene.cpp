#include "scene.h"

Scene::Scene()
{
}

vector<SceneNode*>::iterator Scene::begin() {
    return nodes.begin();
}

vector<SceneNode*>::iterator Scene::end() {
    return nodes.end();
}
