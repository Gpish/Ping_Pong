#include <iostream>
#include "../Headers/buffer.h"

void Buffer::WindowToNDC(GLfloat *vertex, GLfloat range)
{
    *vertex = (2.0 * *vertex) / range - 1.0F;
}
void Buffer::SendDataToGPU(const GLuint &shProgram)
{
    GLfloat vertices[] = {
        800.0F / 2.0F, 3.0F * 600.0F / 4.0F,
        3.0F * 800.0F / 4.0F, 600.0F / 4.0F,
        800.0F / 4.0F, 600.0F / 4.0F
    };

    GLfloat verticesNDC[] = {
        -0.05F, 0.1F,
        0.05F, 0.1F,
        0.05F, -0.1F,
        -0.05F, -0.1F
    };

    GLushort indices[] = {
        0, 1, 2, 3
    };

    GLint numVertices = 100;
    GLfloat circleVerticesNDC[2 * (numVertices + 1)];
    GLushort circleIndices[numVertices + 2];
    GLfloat radius = 0.05F;
    GLdouble theta = glm::radians(360.0F) / static_cast<GLdouble>(numVertices);

    circleVerticesNDC[0] = circleVerticesNDC[1] = 0.0F;
    circleIndices[0] = 0;

    for(int i = 0; i < numVertices; ++i) {
        GLfloat px = radius * glm::cos(i * theta), py = radius * glm::sin(i * theta);
        circleVerticesNDC[2 * (i + 1)] = px;
        circleVerticesNDC[2 * (i + 1) + 1] = py;
        circleIndices[i + 1] = i + 1;
    }
    circleIndices[numVertices + 1] = 1;

    for(int i = 0; i < sizeof(vertices) / sizeof(vertices[0]); i++)  
        WindowToNDC(&vertices[i], i % 2 ? 600.0F : 800.0F);
    
    GLfloat colorPerVertex[] = {
        1.0F, 0.0F, 0.0F,
        0.0F, 1.0F, 0.0F,
        0.0F, 0.0F, 1.0F,
        1.0F, 1.0F, 1.0F
    };

    GLuint ebo;

    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);

    // std::cout << "The vao has val " << vao << "and vbo has value " << vbo << std::endl;
    glBindVertexArray(vao);     // ::Bind(vao)
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNDC) + sizeof(colorPerVertex), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticesNDC), verticesNDC);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(verticesNDC), sizeof(colorPerVertex), colorPerVertex);

    GLuint posIndex = glGetAttribLocation(shProgram, "pos");
    // GLuint colIndex = glGetAttribLocation(shProgram, "col");

    glVertexAttribPointer(posIndex, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (const GLvoid *)0);
    glEnableVertexAttribArray(posIndex);
    // glVertexAttribPointer(colIndex, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid *)(sizeof(verticesNDC)));
    // glEnableVertexAttribArray(colIndex);

    GLuint cvbo, cebo;

    glGenVertexArrays(1, &circleVAO);
    glGenBuffers(1, &cvbo);
    glGenBuffers(1, &cebo);

    glBindVertexArray(circleVAO); 

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(circleIndices), circleIndices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ARRAY_BUFFER, cvbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(circleVerticesNDC) + sizeof(colorPerVertex), NULL, GL_STATIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(circleVerticesNDC), circleVerticesNDC);
    glBufferSubData(GL_ARRAY_BUFFER, sizeof(circleVerticesNDC), sizeof(colorPerVertex), colorPerVertex);

    glVertexAttribPointer(posIndex, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (const GLvoid *)0);
    glEnableVertexAttribArray(posIndex);
    // glVertexAttribPointer(colIndex, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid *)(sizeof(circleVerticesNDC)));
    // glEnableVertexAttribArray(colIndex);
    std::cout << "Buffer Populated and Vertex Attributes Linked Successfully" << std::endl;
}
GLint Buffer::Init(const GLuint &shProgram)
{
    SendDataToGPU(shProgram);
    return 1;
}
void Buffer::Bind()
{
    glBindVertexArray(vao);
}