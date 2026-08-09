#ifndef SHADER
#define SHADER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <string>

class Shader {
public:
    int createFrom(const std::string& sourceFilePath);
    const GLuint& getId() const;
    
protected:
    GLuint id;
    Shader(GLuint id) : id(id) {}   // cant create Shader object like Shader s;

private:
    int compile();
};


#endif