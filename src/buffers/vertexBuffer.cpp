#include "vertexBuffer.hpp"

#include <iostream>

void VertexBuffer::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, Buffer::getId());
}

int VertexBuffer::loadDataFrom(const std::string &filePath)
{
    this->bind();
    this->dataLoader->loadData(filePath, this);
    return 0;
}

void VertexBuffer::enable()
{
    // glVertexAttribPointer(posIndex, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid *)0);
    std::size_t offset = 0;
    for (VertexBufferLayout& layout : this->layouts) {
        glVertexAttribPointer(
            layout.getIndex(), 
            layout.getUnitSize(), 
            layout.getDataType(), 
            layout.getNormalized(),
            layout.getUnitSize() * layout.getDataTypeSize(),
            (const void*)(layout.getOffset() * layout.getDataTypeSize())
        );
        glEnableVertexAttribArray(layout.getIndex());
        offset += layout.getSize() * layout.getDataTypeSize();
    }
}

void VertexBuffer::addLayout(VertexBufferLayout& vertexBufferLayout)
{
    this->layouts.push_back(vertexBufferLayout);
}

// VertexBuffer::VertexBuffer()
// {
// }
