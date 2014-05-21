#include "scenebuilder.h"

void SceneBuilder::buildScene(Scene *scene, RenderFramework *framework)
{
    //EmitterNode *emitNode = new EmitterNode(framework);
    //emitNode->init();
    //scene->addNode(emitNode);

    WaveParticlesNode *waveParticles = new WaveParticlesNode(framework);
    waveParticles->init();
    scene->addNode(waveParticles);
}
