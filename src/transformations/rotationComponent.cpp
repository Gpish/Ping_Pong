#include "rotationComponent.hpp"

void RotationComponent::update(GLfloat deltaTime, Transform& transform)
{
    // LOG_DEBUG("Updating Rotation component:");
    // LOG_DEBUG("Set axis = ", this->axis, " angularSpeed = ", this->angularSpeed);
    transform.setAxis(this->axis);
    GLfloat currentAngleRotated = transform.getAngleRotated();
    transform.setAngleRotated(currentAngleRotated + this->angularSpeed * deltaTime);
}

void RotationComponent::setAxis(const glm::vec3& axis)
{
    this->axis = axis;
}

void RotationComponent::setAngularSpeed(const GLfloat angularSpeed)
{
    this->angularSpeed = angularSpeed;
}

const glm::vec3& RotationComponent::getAxis() const
{
    return this->axis;
}

const GLfloat& RotationComponent::getAngularSpeed() const
{
    return this->angularSpeed;
}
