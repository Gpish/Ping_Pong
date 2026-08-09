assuming all data in a file goes into one VBO => one data type of array

number of attribute pointers used = N
size of each of N arrays and usage
[1, 2, 3, 4] // arr 1 attrib pointer 1
[2, 3, 4, 5] // arr N attrib pointer N
layout-location-0 size-of-unit data-type normalized? (stride) offset // attrib pointer 1
layout-location-1 size-of-unit data-type normalized? (stride) offset // attrib pointer 2





GLint numVertices = 100;
GLfloat circleVerticesNDC[2 * (numVertices + 1)];
GLfloat colorPerVertex[] = {
    1.0F, 0.0F, 0.0F,
    0.0F, 1.0F, 0.0F,
    0.0F, 0.0F, 1.0F,
    1.0F, 1.0F, 1.0F
};

glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

glBufferData(GL_ARRAY_BUFFER, sizeof(verticesNDC) + sizeof(colorPerVertex), NULL, GL_STATIC_DRAW);
glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticesNDC), verticesNDC);
glBufferSubData(GL_ARRAY_BUFFER, sizeof(verticesNDC), sizeof(colorPerVertex), colorPerVertex);

glVertexAttribPointer(posIndex, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (const GLvoid *)0);
glVertexAttribPointer(colIndex, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (const GLvoid *)(sizeof(verticesNDC)));