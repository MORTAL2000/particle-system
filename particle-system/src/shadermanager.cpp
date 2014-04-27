#include "shadermanager.h"

ShaderManager::ShaderManager() {}

ShaderManager::~ShaderManager()
{
    map<string, Shader*>::iterator it;
    for(it = shaders.begin(); it != shaders.end(); ++it) {
        delete it->second;
    }
    shaders.clear();
}

void ShaderManager::init()
{
    defaultAttributes.insert(pair<string, BufferAttribute>("position", VERTEX_BUFFER));
    defaultAttributes.insert(pair<string, BufferAttribute>("uv", TEXTURE_BUFFER));
    defaultAttributes.insert(pair<string, BufferAttribute>("colour", COLOUR_BUFFER));
    defaultAttributes.insert(pair<string, BufferAttribute>("normal", NORMAL_BUFFER));
}

void ShaderManager::addShader(const string& shaderName)
{
    Shader* shader = new Shader(shaderName);
    shader->init(defaultAttributes);
    shaders.insert(pair<string, Shader*>(shaderName, shader));
}

void ShaderManager::addShader(Shader* shader, const string& name)
{
    if(getShader(name) == NULL) {
        shaders.insert(pair<string, Shader*>(name, shader));
    }
}

Shader* ShaderManager::getShader(const string& shaderName) const
{
    Shader* shader = shaders.find(shaderName)->second;
    if(shader == NULL) {
        throw new runtime_error("Didn't found shader " + shaderName + " in the shader library");
    }
    return shader;
}
