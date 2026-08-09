#include "standardVertexArray.hpp"

VertexArray& StandardVertexArray::attachBuffer(Buffer* buffer)
{
    // TODO: insert return statement here
    this->buffers.push_back(buffer);
    return *this;
}

VertexArray& StandardVertexArray::detachBuffer(Buffer* buffer)
{
    // TODO: insert return statement here
    return *this;
}

void StandardVertexArray::enable()
{
    this->bind();
    for (Buffer* buffer : this->buffers) {
        buffer->enable();
    }
}
