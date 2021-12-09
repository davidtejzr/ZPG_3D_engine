#include "Object.h"

Tranformations* Object::getTransformations()
{
    return _trans;
}

void Object::changeShader(Shader* shader)
{
    _shader = shader;
}
