#ifndef STANDARD_SHADER_PROGRAM
#define STANDARD_SHADER_PROGRAM

#include "shader.hpp"
#include "shaderProgram.hpp"

#include <vector>

class StandardShaderProgram : public ShaderProgram {
public:
    ShaderProgram& attachShader(Shader* shader) override;
    ShaderProgram& detachShader(Shader* shader) override;

    void link() override;

private:
    std::vector<Shader*> shaders;
};

#endif