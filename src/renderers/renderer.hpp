#ifndef RENDERER
#define RENDERER

#include "../buffers/vertexArray.hpp"
#include "../shaders/shaderProgram.hpp"

class Renderer {
public:
    virtual void render() = 0;

    ShaderProgram* getShaderProgram() const;

protected:
    Renderer() {}
    Renderer(VertexArray* vertexArray, ShaderProgram* shaderProgram) 
        : vertexArray(vertexArray), shaderProgram(shaderProgram) {}

    VertexArray* vertexArray;
    ShaderProgram* shaderProgram;
};

#endif