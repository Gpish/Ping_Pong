#include "../Headers/window.h"
#include <iostream>

GLint Window::Init() 
{
    if(!glfwInit()) return 0;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);    //required for my MACOS 11.4
#endif

    window = glfwCreateWindow(width, height, name, NULL, NULL);
    if(!window) { std::cout << "Couldnt open window " << std::endl; return 0; }

    glViewport(originX, originY, width, height);
    glfwMakeContextCurrent(window);

    shouldClose = GL_FALSE;
    
    // std::cout << "Window class initializing window pointer in location " << window << std::endl;
    return 1;
}
void Window::TakeInput()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    // if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) { shouldClose = GL_TRUE; }
}
