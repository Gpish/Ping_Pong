#include "triangle.hpp"

// imporve
void Triangle::update(GLfloat deltaTime)
{
    if (InputHandler::isPressed(GLFW_KEY_A)) {
        glm::vec3 axis = this->rotationComponent->getAxis();
        axis.x = 0.0f;
        axis.y = 1.0f;
        this->rotationComponent->setAxis(axis);
    }
    if (InputHandler::isPressed(GLFW_KEY_D)) {
        glm::vec3 axis = this->rotationComponent->getAxis();
        axis.x = 1.0f;
        axis.y = 0.0f;
        this->rotationComponent->setAxis(axis);
    }
    if (InputHandler::isPressed(GLFW_KEY_W)) {
        glm::vec3 direction = this->translationComponent->getDirection();
        direction.x = direction.y = direction.z = 0.0f;
        direction.y = 1.0f;
        this->translationComponent->setDirection(direction);
    }
    if (InputHandler::isPressed(GLFW_KEY_S)) {
        glm::vec3 direction = this->translationComponent->getDirection();
        direction.x = direction.y = direction.z = 0.0f;
        direction.y = -1.0f;
        this->translationComponent->setDirection(direction);
    }

    GameObject::update(deltaTime);
}

Renderer* const Triangle::getRenderer() const
{
    return this->renderer;
}

TranslationComponent* const Triangle::getTranslationComponent() const
{
    return this->translationComponent;
}

RotationComponent* const Triangle::getRotationComponent() const
{
    return this->rotationComponent;
}
