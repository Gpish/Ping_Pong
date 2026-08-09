#include "buffer.hpp"

const GLuint& Buffer::getId() const
{
    return this->id;
}

Buffer::Buffer()
{
    glGenBuffers(1, &this->id);
}

Buffer::Buffer(DataLoader* dataLoader)
{
    glGenBuffers(1, &this->id);
    this->dataLoader = dataLoader;
}