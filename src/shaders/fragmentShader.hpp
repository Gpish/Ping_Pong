#ifndef FRAGMENT_SHADER
#define FRAGMENT_SHADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shader.hpp"

class FragmentShader : public Shader {
public:
    FragmentShader() : Shader(glCreateShader(GL_FRAGMENT_SHADER)) {}
    FragmentShader(const std::string& sourceFilePath) 
        : Shader(glCreateShader(GL_FRAGMENT_SHADER)) { Shader::createFrom(sourceFilePath); };
};

#endif