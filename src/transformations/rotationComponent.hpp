#ifndef ROTATION_COMPONENT
#define ROTATION_COMPONENT

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "transformComponent.hpp"

class RotationComponent : public TransformComponent {
public:
    RotationComponent() : angularSpeed(0.0f), axis(glm::vec3(0.0f)) {}
    RotationComponent(GLfloat angularSpeed, glm::vec3 axis) : angularSpeed(angularSpeed), axis(axis) {}

    void update(GLfloat deltaTime, Transform& transform) override;

    void setAxis(const glm::vec3& axis);
    void setAngularSpeed(const GLfloat angularSpeed);

    const glm::vec3& getAxis() const;
    const GLfloat& getAngularSpeed() const;

private:
    GLfloat angularSpeed;
    glm::vec3 axis;
};


#endif