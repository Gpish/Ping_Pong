#ifndef INPUT_HANDLER
#define INPUT_HANDLER

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <unordered_map>

class InputHandler {
public:
    void setContextWindow(GLFWwindow* window);
    void init();

    static GLboolean isPressed(int key);

private:
    GLFWwindow* currentContextWindow;
    static std::unordered_map<int, GLboolean> keys;

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

};


#endif