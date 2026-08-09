#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "vertexDataLoader.hpp"

GLfloat* VertexDataLoader::fetchAttribData(int size)
{
    GLfloat* data = new GLfloat[size];
    for (int i = 0; i < size; ++i) {
        this->stream >> data[i];
    }
    return data;
}
// size index unitSize type normalized, offset
VertexBufferLayout VertexDataLoader::fetchAttribLayout()
{
    std::string dataType, normalized;
    GLint size, unitSize;
    GLuint index;
    std::size_t offset;

    VertexBufferLayout layout;
    this->stream >> size;
    this->stream >> index;
    this->stream >> unitSize;
    this->stream >> dataType;
    this->stream >> normalized; 
    this->stream >> offset;

    layout.setSize(size);
    layout.setIndex(index);
    layout.setUnitSize(unitSize);
    layout.setDataType(DataLoader::getDataType(dataType));
    layout.setDataTypeSize(DataLoader::getSizeOfDataType(dataType));
    layout.setNormalized(DataLoader::getBoolean(normalized));
    layout.setOffset(offset);

    return layout;
}


int VertexDataLoader::loadData(const std::string& filePath, Buffer* buffer) 
{
    // initialize the file stream to read input file 
    this->stream.open(filePath);
    if (!this->stream.is_open()) {
        std::cout << "Unable to open file: " << filePath << "\n";
        return 0;
    }
    
    // read 
    int noOfAttribs; stream >> noOfAttribs;
    GLfloat* vertexData[noOfAttribs];
    int vertexDataSize[noOfAttribs];
    for (int attrib = 0; attrib < noOfAttribs; ++attrib) {
        VertexBufferLayout layout = this->fetchAttribLayout();
        
        vertexDataSize[attrib] = layout.size;
        vertexData[attrib] = this->fetchAttribData(layout.size);    // delete the heap memory

        if (buffer) {
            dynamic_cast<VertexBuffer*>(buffer)->addLayout(layout);     // try to remove this dynamic cast
        }
    }

    int totalSize = 0;
    for (int i = 0; i < noOfAttribs; ++i) {
        totalSize += vertexDataSize[i];
    }

    // load the data into target buffer 
    glBufferData(GL_ARRAY_BUFFER, totalSize * sizeof(GLfloat), NULL, GL_STATIC_DRAW);   // to-do: parametrize usage
    int prev = 0;
    for (int attrib = 0; attrib < noOfAttribs; ++attrib) {
        glBufferSubData(GL_ARRAY_BUFFER, prev, vertexDataSize[attrib] * sizeof(GLfloat), vertexData[attrib]);
        prev += vertexDataSize[attrib] * sizeof(GLfloat);
    }

    return 1;
}

