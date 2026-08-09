#include "translationComponent.hpp"

void TranslationComponent::update(GLfloat deltaTime, Transform& transform)
{
    // LOG_DEBUG("Before update ", transform.getPosition());

    glm::vec3 currentPosition = transform.getPosition();
    currentPosition += this->direction * this->speed * deltaTime;
    transform.setPosition(currentPosition);

    // LOG_DEBUG("After update ", transform.getPosition());
}

const glm::vec3& TranslationComponent::getDirection() const
{
    return this->direction;
}

const GLfloat& TranslationComponent::getSpeed() const
{
    return this->speed;
}

void TranslationComponent::setDirection(const glm::vec3& direction)
{
    this->direction = direction;
}

void TranslationComponent::setSpeed(const GLfloat speed)
{
    this->speed = speed;
}
