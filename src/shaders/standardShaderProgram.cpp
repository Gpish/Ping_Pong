#include "standardShaderProgram.hpp"

ShaderProgram& StandardShaderProgram::attachShader(Shader* shader)
{
    this->shaders.push_back(shader);
    glAttachShader(ShaderProgram::getId(), shader->getId());
    return *this;
}

ShaderProgram& StandardShaderProgram::detachShader(Shader* shader)
{
    return *this;
}

void StandardShaderProgram::link()
{
    glLinkProgram(ShaderProgram::getId());
}
