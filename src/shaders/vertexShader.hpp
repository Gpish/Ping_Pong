#ifndef VERTEX_SHADER
#define VERTEX_SHADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"

class VertexShader : public Shader {
public:
    VertexShader() : Shader(glCreateShader(GL_VERTEX_SHADER)) {}
    VertexShader(const std::string& sourceFilePath) 
        : Shader(glCreateShader(GL_VERTEX_SHADER)) { Shader::createFrom(sourceFilePath); };
};

#endif