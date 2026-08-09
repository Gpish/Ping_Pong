#include "vertexArray.hpp"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &this->id);
}

void VertexArray::bind()
{
    glBindVertexArray(this->id);
}

const GLuint &VertexArray::getId() const
{
    return this->id;
}
