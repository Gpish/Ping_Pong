#ifndef BUFFER
#define BUFFER

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "../dataloaders/dataLoader.hpp"

class Buffer {
public:
    virtual void bind() = 0;
    virtual int loadDataFrom(const std::string& filePath) = 0;
    virtual void enable() = 0;

    const GLuint& getId() const;

    virtual ~Buffer() = default;

protected:
    Buffer();
    Buffer(DataLoader* dataLoader);
    DataLoader* dataLoader;

private:
    GLuint id;
};


#endif