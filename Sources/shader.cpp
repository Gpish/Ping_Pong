        /*
            implement robust error handling
        */
#include <string>
#include <iostream>             // remove the need for this by using error handling(throw catch)
#include <fstream>              //includes ifstream, ofstream, fstream and iostream
#include <sstream>

#include "../Headers/shader.h"
using namespace std;        //remove

// GLuint Shader::program = glCreateProgram();
Shader::Shader(const char *vsSourcePath, const char *fsSourcePath) : vs(0), fs(0), program(0)
{
    VertexSource(vsSourcePath);
    FragmentSource(fsSourcePath);
    Make();
}
GLint Shader::Init(const char *vsSourcePath, const char *fsSourcePath)
{
    VertexSource(vsSourcePath);
    FragmentSource(fsSourcePath);
    Make();
    return 1;
}
void Shader::VertexSource(const char *vsSourcePath) {
    /*
        need to stream vs and fs text files 
        as char arrays into first a string var
        then convert the string to C style string(char array) with c_str()
    */
    ifstream sfStream(vsSourcePath);         // source code input file stream : sfStream
    if(!sfStream) {
        cout << "Cant open file" << endl;
    }
    ostringstream ssStream;                  // source code output string stream : ssStream
    ssStream << sfStream.rdbuf() << ends;    // ends : adds 0 terminator to char array

    string sCode = ssStream.str();           // stream to string
    const char *vsSourceCode = sCode.c_str();            // string to C style char array

    sfStream.close();

    vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vsSourceCode, NULL);
}
void Shader::FragmentSource(const char *fsSourcePath) {
    ifstream sfStream(fsSourcePath);         // source code input file stream : sfStream
    if(!sfStream) {
        cout << "Cant open file" << endl;
    }
    ostringstream ssStream;                  // source code output string stream : ssStream
    ssStream << sfStream.rdbuf() << ends;    // ends : adds 0 terminator to char array

    string sCode = ssStream.str();           // stream to string
    const char *fsSourceCode = sCode.c_str();            // string to C style char array

    sfStream.close();

    fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, GLsizei(1), &fsSourceCode, NULL);
}
GLint Shader::Make()
{
    glCompileShader(vs);

    GLint success;
    glGetShaderiv(vs, GL_COMPILE_STATUS, &success);
    if(!success) {
        cout << "Vertex Shader Compilation Failed" << endl;
        return 0;
    } else cout << "Vertex Shader Compiled Successfully" << endl;
    glCompileShader(fs);
    
    glGetShaderiv(fs, GL_COMPILE_STATUS, &success);
    if(!success) {
        cout << "Fragment Shader Compilation Failed" << endl;
        return 0;
    } else cout << "Fragment Shader Compiled Successfully" << endl;

    program = glCreateProgram();
    // GLuint dummyProgram = program;   // dummyShaderProgram GLuint works
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    glLinkProgram(program);

    GLint success_link;
    glGetProgramiv(program, GL_LINK_STATUS, &success_link);    
    if(!success_link){
        cout << "Unsuccesful shader program linking" << endl;
        return 0;
    } else cout << "Shaders Linked Successfully" << endl;
    return 1;
}
void Shader::Use() { glUseProgram(program); }
void Shader::SetUniform(const char *name, glm::mat4 &value) 
{
    GLuint loc = glGetUniformLocation(program, "transformation");
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(value));
}