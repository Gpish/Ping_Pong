#ifndef VERTEX_DATA_LOADER
#define VERTEX_DATA_LOADER

#include <string>
#include <fstream>
#include <iostream>

#include "dataLoader.hpp"
#include "../buffers/buffer.hpp"
#include "../buffers/vertexBuffer.hpp"
#include "../buffers/vertexBufferLayout.hpp"

class VertexDataLoader : public DataLoader {
public:
    int loadData(const std::string& filePath, Buffer* buffer) override;

private:
    std::ifstream stream;
    GLfloat* fetchAttribData(int size);
    VertexBufferLayout fetchAttribLayout();
};


#endif