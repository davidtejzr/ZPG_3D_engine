#include "ShaderManager.h"

ShaderManager* ShaderManager::_instance = nullptr;

ShaderManager::ShaderManager()
{
    _shaders = new std::vector<Shader>();
    _shaders->push_back(Shader("constant.vert", "constant.frag"));
    _shaders->push_back(Shader("lambert.vert", "lambert.frag"));
    _shaders->push_back(Shader("phong.vert", "phong.frag"));
    _shaders->push_back(Shader("blinn.vert", "blinn.frag"));
    _shaders->push_back(Shader("cubemap_constant.vert", "cubemap_constant.frag"));
}

ShaderManager* ShaderManager::getInstance()
{
    if (_instance == nullptr)
    {
        _instance = new ShaderManager();
    }

    return _instance;
}

Shader* ShaderManager::getShader(int id)
{
    return &_shaders->at(id);
}
