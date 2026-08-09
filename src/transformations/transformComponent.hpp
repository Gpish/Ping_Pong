#ifndef TRANSFORM_COMPONENT
#define TRANSFORM_COMPONENT

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm/glm.hpp>
#include <GLM/glm/gtc/matrix_transform.hpp>

#include "transform.hpp"

class TransformComponent {
public:
    virtual ~TransformComponent() = default;
    
    virtual void update(GLfloat deltaTime, Transform& transform) = 0;
};


#endif