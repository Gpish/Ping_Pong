#include "inputHandler.hpp"

std::unordered_map<int, GLboolean> InputHandler::keys;

void InputHandler::setContextWindow(GLFWwindow* window)
{
    this->currentContextWindow = window;
}

void InputHandler::init()
{
    glfwSetKeyCallback(this->currentContextWindow, keyCallback);
}

GLboolean InputHandler::isPressed(int key)
{
    return keys[key];
}

void InputHandler::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)   keys[key] = GL_TRUE;
    if (action == GLFW_RELEASE) keys[key] = GL_FALSE;
}
