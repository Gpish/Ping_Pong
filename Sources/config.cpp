#include "../Headers/config.h"

Shader Config::shader = Shader();
Buffer Config::buffer = Buffer();
Window Config::window = Window();
// GLboolean Config::isPressed[9] = { GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE, GLFW_FALSE };
GLboolean Config::isPressed[9] = { GLFW_FALSE };

GLint Config::Init()
{
    window.Init();
    shader.Init("Sources/Shaders/vsSourceTextAlt.txt", "Sources/Shaders/fsSourceText.txt");
    buffer.Init(shader.GetShaderID());
    for(GLsizei i = 0; i < Key::NA; ++i) isPressed[i] = GL_FALSE;
    glfwSetKeyCallback(window.GetWindowPointer(), OnKeyCall);
}
void Config::Use() 
{
    shader.Use();
    buffer.Bind();
}
void Config::UseCircle()
{
    shader.Use();
    buffer.BindCircle();
}
void Config::OnKeyCall(GLFWwindow *win, int key, int scancode, int action, int mods) 
{
    if(action == GLFW_PRESS) {
        switch(key) {
            case GLFW_KEY_ESCAPE :  isPressed[Key::ESC] =   GLFW_TRUE; break;
            case GLFW_KEY_UP :      isPressed[Key::UP] =    GLFW_TRUE; break;
            case GLFW_KEY_DOWN :    isPressed[Key::DOWN] =  GLFW_TRUE; break;
            case GLFW_KEY_RIGHT :   isPressed[Key::RIGHT] = GLFW_TRUE; break;
            case GLFW_KEY_LEFT :    isPressed[Key::LEFT] =  GLFW_TRUE; break;
            case GLFW_KEY_D:        isPressed[Key::D] =     GLFW_TRUE; break;
            case GLFW_KEY_S :       isPressed[Key::S] =     GLFW_TRUE; break;
            case GLFW_KEY_A :       isPressed[Key::A] =     GLFW_TRUE; break;
            case GLFW_KEY_W :       isPressed[Key::W] =     GLFW_TRUE; break;
            case GLFW_KEY_Z :       isPressed[Key::Z] =     GLFW_TRUE; break;
            case GLFW_KEY_X :       isPressed[Key::X] =     GLFW_TRUE; break;
        }
    }
    if(action == GLFW_RELEASE) {
        switch(key) {
            case GLFW_KEY_UP :      isPressed[Key::UP]   =  GLFW_FALSE; break;
            case GLFW_KEY_DOWN :    isPressed[Key::DOWN] =  GLFW_FALSE; break;
            case GLFW_KEY_RIGHT :   isPressed[Key::RIGHT] = GLFW_FALSE; break;
            case GLFW_KEY_LEFT :    isPressed[Key::LEFT] =  GLFW_FALSE; break;
            case GLFW_KEY_D:        isPressed[Key::D] =     GLFW_FALSE; break;
            case GLFW_KEY_S :       isPressed[Key::S] =     GLFW_FALSE; break;
            case GLFW_KEY_A :       isPressed[Key::A] =     GLFW_FALSE; break;
            case GLFW_KEY_W :       isPressed[Key::W] =     GLFW_FALSE; break;
            case GLFW_KEY_Z :       isPressed[Key::Z] =     GLFW_FALSE; break;
            case GLFW_KEY_X :       isPressed[Key::X] =     GLFW_FALSE; break;
        }
    }
}