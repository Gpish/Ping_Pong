#ifndef CONFIGURATIONS
#define CONFIGURATIONS

#include "buffer.h"
#include "shader.h"
#include "window.h"

class Config {
    private:
    protected:
            static Shader shader;
            static Buffer buffer;
            static Window window;
            enum Key { UP, DOWN, RIGHT, LEFT, W, S, A, D, X, Z, ESC, NA};
            static GLboolean isPressed[9];
            static void OnKeyCall(GLFWwindow *window, int key, int scancode, int action, int mods);
    public:
            Config() {}
            static GLint Init();
            static void Use();
            static void UseCircle();
};

#endif
