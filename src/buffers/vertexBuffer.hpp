#ifndef VERTEX_BUFFER
#define VERTEX_BUFFER

#include <string>
#include <vector>

#include "buffer.hpp"
#include "vertexBufferLayout.hpp"
#include "../dataloaders/dataLoader.hpp"

class VertexBuffer : public Buffer {
public:
    VertexBuffer() : Buffer() {};
    VertexBuffer(DataLoader* dataLoader) : Buffer(dataLoader) {};
    // ~VertexBuffer() override;

    void bind() override;
    void enable() override;
    int loadDataFrom(const std::string& filePath) override;

    void addLayout(VertexBufferLayout& vertexBufferLayout);

private:
    std::vector<VertexBufferLayout> layouts;
    
};


#endif