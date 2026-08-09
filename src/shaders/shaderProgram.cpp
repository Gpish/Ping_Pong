#include "shaderProgram.hpp"

void ShaderProgram::use()
{
    glUseProgram(this->id);
}

void ShaderProgram::updateTransformationMatrix4fv(const glm::mat4& transformation)
{
    GLuint uniformTransformationLocation = glGetUniformLocation(this->id, "transformation");
    glUniformMatrix4fv(uniformTransformationLocation, 1, GL_FALSE, glm::value_ptr(transformation));
}

const GLuint &ShaderProgram::getId() const
{
    return this->id;
}
