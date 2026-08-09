#ifndef SHADER_PROGRAM
#define SHADER_PROGRAM

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm/glm.hpp>
#include <GLM/glm/gtc/matrix_transform.hpp>
#include <GLM/glm/gtc/type_ptr.hpp>

#include "shader.hpp"

class ShaderProgram {
public:
    virtual ShaderProgram& attachShader(Shader* shader) = 0;
    virtual ShaderProgram& detachShader(Shader* shader) = 0;

    virtual void link() = 0;
    void use();
    
    const GLuint& getId() const;

    void updateTransformationMatrix4fv(const glm::mat4& transformation);

protected:
    ShaderProgram() : id(glCreateProgram()) {}

private:
    GLuint id;
};

#endif