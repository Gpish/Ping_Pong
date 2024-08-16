#ifndef BUFFER
#define BUFFER

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/glm.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/matrix_transform.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/type_ptr.hpp"

class Buffer {
    private:
            GLuint vao, vbo;
            GLuint circleVAO;
            void WindowToNDC(GLfloat *, GLfloat);
            void SendDataToGPU(const GLuint &shProgram);
    public:
            Buffer() : vao(0), vbo(0) {}
            Buffer(const Buffer &buf) : vao(buf.vao), vbo(buf.vbo) {}
            Buffer(const GLuint &shProgram) : vao(0), vbo(0) { SendDataToGPU(shProgram); }
            GLint Init(const GLuint &shProgram);
            void Bind();
            void BindCircle() { glBindVertexArray(circleVAO); }
};

#endif