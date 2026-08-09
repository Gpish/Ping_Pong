#ifndef SCALING_COMPONENT
#define SCALING_COMPONENT

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "transformComponent.hpp"

class ScalingComponent : public TransformComponent {
public:
    ScalingComponent() : by(glm::vec3(0.0f)) {}
    ScalingComponent(glm::vec3 by) : by(by) {}

    void update(GLfloat deltaTime, Transform& transform) override;

private:
    glm::vec3 by;
};


#endif