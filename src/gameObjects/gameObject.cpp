#include "gameObject.hpp"

void GameObject::update(GLfloat deltaTime)
{
    for (TransformComponent* transformComponent : this->transformComponents) {
        transformComponent->update(deltaTime, this->transform);
    }
}

// improve
void GameObject::render()
{
    // have a check to check if the matrix has changed then apply the changes else just render as is
    this->renderer->getShaderProgram()->updateTransformationMatrix4fv(this->transform.getModelMatrix());
    this->renderer->render();
}

void GameObject::addTransformComponent(TransformComponent* transformComponent)
{
    this->transformComponents.push_back(transformComponent);
}
