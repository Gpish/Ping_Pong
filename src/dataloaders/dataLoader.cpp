#include "dataLoader.hpp"

GLenum DataLoader::getDataType(const std::string& type) 
{
    if (type == "float") return GL_FLOAT;

    return GL_FLOAT;
}

GLsizei DataLoader::getSizeOfDataType(const std::string& type)
{
    if (type == "float") return sizeof(GLfloat);
    
    return sizeof(GLfloat);
}

GLboolean DataLoader::getBoolean(const std::string& boolean)
{
    if (boolean == "true") return GL_TRUE;
    
    return GL_FALSE;
}