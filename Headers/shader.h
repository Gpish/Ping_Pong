#ifndef SHADER
#define SHADER

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/glm.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/matrix_transform.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/type_ptr.hpp"

/*
    You dont want functions outside the class
    access private members of the class, you need wrapper
    or design change to allow for the same functionality wo
    accesing private data
*/
class Shader {
    private:
            GLuint vs, fs;              
            GLuint program;             // holds the entire Shader program
            void VertexSource(const char *vsSourcePath);
            void FragmentSource(const char *fsSourcePath);
            GLint Make();
    public:
            Shader() : vs(0), fs(0), program(0) {}
            Shader(const Shader &sh) : vs(sh.vs), fs(sh.fs), program(sh.program) {}
            Shader(const char *vsSourcePath, const char *fsSourcePath);
            GLint Init(const char *vsSourcePath, const char *fsSourcePath);
            GLuint &GetShaderID() { return program; }
            void Use();
            void SetUniform(const char *name, glm::mat4 &value);
            
} ;

#endif