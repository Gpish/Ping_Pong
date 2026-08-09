#ifndef TRANSLATION_COMPONENT
#define TRANSLATION_COMPONENT

#include "transformComponent.hpp"

class TranslationComponent : public TransformComponent {
public:
    TranslationComponent() : direction(glm::vec3(0.0f)), speed(0.0f) {}
    TranslationComponent(glm::vec3 direction, GLfloat speed) : direction(direction), speed(speed) {}

    void update(GLfloat deltaTime, Transform& transform) override;

    const glm::vec3& getDirection() const;
    const GLfloat& getSpeed() const;

    void setDirection(const glm::vec3& direction);
    void setSpeed(const GLfloat speed);

private:
    glm::vec3 direction;
    GLfloat speed;
};


#endif