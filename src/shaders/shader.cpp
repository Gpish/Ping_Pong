#include "shader.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

int Shader::createFrom(const std::string &sourceFilePath)
{
    std::ifstream inputStream(sourceFilePath);
    if(!inputStream) {
        std::cout << "Cant open Shader file: " << sourceFilePath << std::endl;
    }

    std::ostringstream outputStringStream;
    outputStringStream << inputStream.rdbuf();    // ends : adds 0 terminator to char array

    std::string sourceCodeString = outputStringStream.str();           // stream to string
    const char *sourceCodePtr = sourceCodeString.c_str();            // string to C style char array

    glShaderSource(this->id, GLsizei(1), &sourceCodePtr, NULL);
    this->compile();

    return this->id;
}

const GLuint &Shader::getId() const
{
    return this->id;
}

int Shader::compile()
{
    glCompileShader(this->id);
    return 1;
}
