#define GLFW_INCLUDE_NONE
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "buffers/vertexBuffer.hpp"
#include "shaders/vertexShader.hpp"
#include "shaders/fragmentShader.hpp"
#include "buffers/standardVertexArray.hpp"
#include "shaders/standardShaderProgram.hpp"
#include "renderers/triangleRenderer.hpp"
#include "transformations/transformComponent.hpp"
#include "transformations/translationComponent.hpp"
#include "transformations/rotationComponent.hpp"
#include "gameObjects/gameObject.hpp"
#include "gameObjects/triangle.hpp"
#include "dataloaders/vertexDataLoader.hpp"
#include "inputHandlers/inputHandler.hpp"
#include "logger/logger.hpp"

#include <iostream>

int init() 
{
    if(!glfwInit()) 
    {
        std::cerr << "Failed to load GLFW\n";
        return 0;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);    //required for my MACOS 11.4

    return 1;
}

void testVertexDataLoader() 
{
    VertexDataLoader vertexDataLoader;
    int loaded = vertexDataLoader.loadData("./src/resources/vertexData/triangle.txt", nullptr);
    std::cout << (loaded ? "Data Loader successful " : "Data Loader unsuccessful") << "\n";
}

void testVertexBuffer() 
{
    VertexDataLoader vertexDataLoader;
    VertexBuffer vertexBuffer(&vertexDataLoader);
    std::cout << "Vertex Buffer id: " << vertexBuffer.getId() << "\n";
    vertexBuffer.loadDataFrom("./src/resources/vertexData/triangle.txt");
    std::cout << "Vertex Buffer Data Load Successful" << "\n";
    vertexBuffer.enable();
    std::cout << "Vertex Buffer enabled successfully" << "\n";
}

void testVertexShader() 
{
    VertexShader vertexShader("./src/resources/vertexData/triangle.txt");
    std::cout << "Vertex Shader id: "  << vertexShader.getId() << "\n";
}

void testVertexArray() 
{
    VertexDataLoader vertexDataLoader;
    VertexBuffer vbo(&vertexDataLoader);
    vbo.loadDataFrom("./src/resources/vertexData/triangle.txt.txt");
    StandardVertexArray vao;
    vao.attachBuffer(&vbo);
    vao.enable();
    vao.bind();
    std::cout << "Vertex array initialized successfully" << "\n";
}

void testShaderProgram() 
{
    StandardShaderProgram shaderProgram;
    VertexShader vertexShader("./src/resources/vertexData/triangle.txt");
    shaderProgram.attachShader(&vertexShader);
    shaderProgram.link();
    shaderProgram.use();
    std::cout << "Shader program successful" << "\n";
}


int main(int argc, char **argv) 
{
    if (!init()) return 0;

    GLFWwindow* window = glfwCreateWindow(600, 400, "Game Design", NULL, NULL);

    if (!window) 
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwDestroyWindow(window);
        glfwTerminate();
        return -1;
    }
    
    // testVertexDataLoader();
    // testVertexBuffer();
    // testVertexShader();
    // testVertexArray();
    // testShaderProgram();

    VertexDataLoader vertexDataLoader;
    VertexBuffer vertexBuffer(&vertexDataLoader);
    vertexBuffer.loadDataFrom("./src/resources/vertexData/triangle.txt");
    LOG_INFO("Vertex data loaded successfully into vertex buffer with id = ", vertexBuffer.getId());

    VertexShader vertexShader("./src/resources/shaders/triangle.vertexShader");
    FragmentShader fragmentShader("./src/resources/shaders/triangle.fragmentShader");
    LOG_INFO("Shaders initialized successfully");

    StandardShaderProgram standardShaderProgram;
    standardShaderProgram.attachShader(&vertexShader);
    standardShaderProgram.attachShader(&fragmentShader);
    standardShaderProgram.link();
    LOG_INFO("Shader Program set up successfully with program id = ", standardShaderProgram.getId());

    StandardVertexArray standardVertexArray;
    standardVertexArray.attachBuffer(&vertexBuffer);
    standardVertexArray.enable();
    LOG_INFO("Vertex Array configured successfully with id = ", standardVertexArray.getId());

    TriangleRenderer triangleRenderer(&standardVertexArray, &standardShaderProgram);

    std::vector<GameObject*> gameObjects;
    Triangle* triangle = new Triangle(&triangleRenderer);
    
    RotationComponent* rotationComponent = triangle->getRotationComponent();
    rotationComponent->setAngularSpeed(10.0f);
    rotationComponent->setAxis(glm::vec3(1.0f, 0.0f, 0.0f));

    TranslationComponent* translationComponent = triangle->getTranslationComponent();
    translationComponent->setSpeed(1.0f);

    gameObjects.push_back(triangle);

    InputHandler inputHandler;
    inputHandler.setContextWindow(window);
    inputHandler.init();

    double lastTime = glfwGetTime();
    while (!glfwWindowShouldClose(window)) 
    {
        double currentTime = glfwGetTime();
        double deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // fresh page
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        for (GameObject* gameObject : gameObjects) {
            gameObject->update(deltaTime);
            gameObject->render();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}