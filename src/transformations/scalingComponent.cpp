#include "scalingComponent.hpp"

void ScalingComponent::update(GLfloat deltaTime, Transform& transform)
{
    transform.setScale(this->by);
}
