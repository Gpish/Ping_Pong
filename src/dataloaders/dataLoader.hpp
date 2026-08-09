#ifndef DATA_LOADER
#define DATA_LOADER

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Buffer;

class DataLoader {
public:
    virtual int loadData(const std::string& filePath, Buffer* buffer) = 0;

protected:
    GLenum getDataType(const std::string& type);
    GLsizei getSizeOfDataType(const std::string& type);
    GLboolean getBoolean(const std::string& boolean);
};

#endif