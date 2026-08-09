#include "transform.hpp"

const glm::mat4& Transform::getModelMatrix() const
{
    if (this->updated) {
        glm::mat4 translation = glm::translate(glm::mat4(1.0f), this->position);
        glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), glm::radians(this->angleRotated), this->axis);
        glm::mat4 scale = glm::scale(glm::mat4(1.0f), this->scale);

        this->modelMatrix = rotation * scale * translation;
        this->updated = GL_FALSE;
        // LOG_DEBUG("Model matrix is updated");
    }

    // LOG_DEBUG("Model matrix = ", this->modelMatrix);
    return this->modelMatrix;
}

const glm::vec3& Transform::getPosition() const
{
    return this->position;
}

const glm::vec3& Transform::getAxis() const
{
    return this->axis;
}

const GLfloat& Transform::getAngleRotated() const
{
    return this->angleRotated;
}

const glm::vec3& Transform::getScale() const
{
    return this->scale;
}

void Transform::setPosition(const glm::vec3& position)
{
    this->position = position;
    this->updated = GL_TRUE;
}

void Transform::setAxis(const glm::vec3& axis)
{
    this->axis = axis;
    this->updated = GL_TRUE;
}

void Transform::setAngleRotated(const GLfloat angleRotated)
{
    this->angleRotated = angleRotated;
    this->updated = GL_TRUE;
}

void Transform::setScale(const glm::vec3& scale)
{
    this->scale = scale;
    this->updated = GL_TRUE;
}
