#ifndef STANDARD_VERTEX_ARRAY
#define STANDARD_VERTEX_ARRAY

#include "vertexArray.hpp"

#include <vector>

class StandardVertexArray : public VertexArray {
public:
    VertexArray& attachBuffer(Buffer* buffer) override;
    VertexArray& detachBuffer(Buffer* buffer) override;
    void enable() override;

private:
    std::vector<Buffer*> buffers;
};

#endif