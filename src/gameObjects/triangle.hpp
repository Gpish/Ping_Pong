#ifndef TRIANGLE
#define TRIANGLE

#include "gameObject.hpp"
#include "../inputHandlers/inputHandler.hpp"
#include "../transformations/translationComponent.hpp"
#include "../transformations/rotationComponent.hpp"

class Triangle : public GameObject {
public:
    Triangle(Renderer* renderer) : GameObject(renderer) {
        translationComponent = new TranslationComponent();
        rotationComponent = new RotationComponent();

        GameObject::addTransformComponent(translationComponent);
        GameObject::addTransformComponent(rotationComponent);
    }

    void update(GLfloat deltaTime) override;

    Renderer* const getRenderer() const;
    TranslationComponent* const getTranslationComponent() const;
    RotationComponent* const getRotationComponent() const;


private:
    TranslationComponent* translationComponent;
    RotationComponent* rotationComponent;
};

#endif