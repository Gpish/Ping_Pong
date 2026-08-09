#ifndef TRIANGLE_RENDERER
#define TRIANGLE_RENDERER

#include "renderer.hpp"
#include "../buffers/vertexArray.hpp"
#include "../shaders/shaderProgram.hpp"

class TriangleRenderer : public Renderer {
public:
    TriangleRenderer(VertexArray* vertexArray, ShaderProgram* shaderProgram) 
        : Renderer(vertexArray, shaderProgram) {}
    
    void render() override;
};

#endif