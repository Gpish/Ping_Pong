#include "triangleRenderer.hpp"

void TriangleRenderer::render()
{
    this->shaderProgram->use();
    this->vertexArray->bind();
    glDrawArrays(GL_TRIANGLE_FAN, 0, 3);
}