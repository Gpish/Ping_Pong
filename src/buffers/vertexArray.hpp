#ifndef VERTEX_ARRAY
#define VERTEX_ARRAY

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "buffer.hpp"

class VertexArray {
public:
    virtual VertexArray& attachBuffer(Buffer* buffer) = 0;
    virtual VertexArray& detachBuffer(Buffer* buffer) = 0;
    
    virtual void enable() = 0;
    void bind();

    const GLuint& getId() const;

protected:
    VertexArray();

private:
    GLuint id;
};

#endif