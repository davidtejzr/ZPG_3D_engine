#include "ShaderManager.h"

ShaderManager::ShaderManager()
{
    _shaders = new std::vector<Shader>();
    _shaders->push_back(Shader("constant.vert", "constant.frag"));
    _shaders->push_back(Shader("lambert.vert", "lambert.frag"));
    _shaders->push_back(Shader("phong.vert", "phong.frag"));
}

Shader* ShaderManager::getShader(int id)
{
    return &_shaders->at(id);
}
