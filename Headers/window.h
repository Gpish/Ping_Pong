#ifndef WINDOW
#define WINDOW

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

class Window {
    protected:
            GLfloat height, width;
            GLfloat originX, originY;
            GLFWwindow *window;
            GLboolean shouldClose;
            const char *name;
    public:
            Window(GLfloat oX = 0.0F, GLfloat ht = 600.0f, GLfloat oY = 0.0F, GLfloat wd = 800.0f, const char *name = "Shape") : height(ht), width(wd), window(nullptr), shouldClose(GL_FALSE), originX(oX), originY(oY), name(name) {}
            GLint Init();
            GLboolean Close() const { return shouldClose or glfwWindowShouldClose(window); }
            void Close(GLboolean flag) { shouldClose = flag; }
            GLfloat GetHeight() const { return height; }
            GLfloat GetWidth() const { return width; }
            GLfloat GetOriginX() const { return originX; }
            GLfloat GetOriginY() const { return originY; }
            GLdouble GetTime() const { return glfwGetTime(); }
            GLFWwindow *const GetWindowPointer() const { return window; }
            void SwapBuffers() const { glfwSwapBuffers(window); }
            void ProcessEvents() const { glfwPollEvents(); }
            void TakeInput();
};


#endif