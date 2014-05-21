#ifndef SCENEBUILDER_H
#define SCENEBUILDER_H

#include "scene.h"
#include "emitternode.h"
#include "waveparticlesnode.h"
#include "renderframework.h"
#include "mesh.h"
#include "GL/glew.h"

class SceneBuilder
{
public:
    SceneBuilder() {}

    static void buildScene(Scene *scene, RenderFramework *framework);
};

#endif // SCENEBUILDER_H
