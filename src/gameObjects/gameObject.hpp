#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <GLM/glm/glm.hpp>

#include "../renderers/renderer.hpp"
#include "../transformations/transformComponent.hpp"

class GameObject {
public:
    virtual void update(GLfloat deltaTime);
    void render();

    void addTransformComponent(TransformComponent* transformComponent);

protected:
    GameObject() : renderer(nullptr) {}
    GameObject(Renderer* renderer) : renderer(renderer) {}

    Renderer* renderer;
    Transform transform;

    std::vector<TransformComponent*> transformComponents;
};

#endif