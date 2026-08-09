#ifndef TRANSFORMATION
#define TRANSFORMATION

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm/glm.hpp>
#include <GLM/glm/gtc/matrix_transform.hpp>
#include "../logger/logger.hpp"

class Transform {
public:
    Transform() : position(glm::vec3(0.0f)), 
                  axis(glm::vec3(0.0f)), 
                  angleRotated(0.0f), 
                  scale(glm::vec3(1.0f)),
                  modelMatrix(glm::mat4(1.0f)),
                  updated(GL_FALSE) {}

    const glm::mat4& getModelMatrix() const;

    const glm::vec3& getPosition() const;
    const glm::vec3& getAxis() const;
    const GLfloat& getAngleRotated() const;
    const glm::vec3& getScale() const;

    void setPosition(const glm::vec3& position);
    void setAxis(const glm::vec3& axis);
    void setAngleRotated(const GLfloat angleRotated);
    void setScale(const glm::vec3& scale);

private:
    glm::vec3 position;
    glm::vec3 axis;
    GLfloat angleRotated;
    glm::vec3 scale;

    mutable glm::mat4 modelMatrix;

    mutable GLboolean updated;
};


#endif