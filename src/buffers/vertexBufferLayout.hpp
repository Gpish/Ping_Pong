#ifndef VERTEX_BUFFER_LAYOUT
#define VERTEX_BUFFER_LAYOUT

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <cstddef>
// size index unitSize type normalized, offset
class VertexBufferLayout {
public:
    GLint size;
    GLuint index;
    GLint unitSize;
    GLenum dataType;
    GLsizei dataTypeSize;
    GLboolean normalized;
    std::size_t offset;

    void setSize(GLint size)                    { this->size = size; }
    void setIndex(GLuint index)                 { this->index = index; }
    void setUnitSize(GLint unitSize)            { this->unitSize = unitSize; }
    void setDataType(GLint type)                { this->dataType = type; }
    void setDataTypeSize(GLsizei dataTypeSize)  { this->dataTypeSize = dataTypeSize; }
    void setNormalized(GLint normalized)        { this->normalized = normalized; }
    void setOffset(std::size_t offset)          { this->offset = offset; }

    GLint getSize()             { return this->size; }
    GLuint getIndex()           { return this->index; }
    GLint getUnitSize()         { return this->unitSize; }
    GLenum getDataType()        { return this->dataType; }
    GLsizei getDataTypeSize()   { return this->dataTypeSize; }
    GLboolean getNormalized()   { return this->normalized; }
    std::size_t getOffset()     { return this->offset; }

};

#endif