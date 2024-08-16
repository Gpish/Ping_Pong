#include "../Headers/paddle.h"

bool Ball::CheckCollision(const Paddle &p1, const Paddle &p2)
{
    GLfloat lowerHeight1 = p1.position.y - p1.height * p1.size.y,
            upperHeight1 = p1.position.y + p1.height * p1.size.y;
    
    GLfloat lowerHeight2 = p2.position.y - p2.height * p2.size.y,
            upperHeight2 = p2.position.y + p2.height * p2.size.y;
    
    GLfloat rightWall = p1.position.x - p1.width * p1.size.x,
            leftWall = p2.position.x + p2.width * p2.size.x;
    
    GLfloat right = position.x + radius * size,
            left = position.x - radius * size;
    
    if(right >= rightWall) {
        if(lowerHeight1 <= position.y and position.y <= upperHeight1) {
            velocity.x *= -1;
            position.x = rightWall - radius * size;
        }
        else {
            // velocity.x = velocity.y = 0.0F;
            // return true;
        }
    }
    
    if(left <= leftWall) {
        if(lowerHeight2 <= position.y and position.y <= upperHeight2) {
            velocity.x *= -1;
            position.x = leftWall + radius * size;
        }
        else {
            // velocity.x = velocity.y = 0.0F;
            // return true;
        }
    }
    return false;
}
void Ball::Bounce(GLdouble dt)
{
    velocity.y += g * dt;
    position.y += velocity.y * dt;

    position.x += velocity.x * dt;
    if (position.y - radius * size <= -1.0F) {
        position.y = -1.0F + radius * size;
        velocity.y *= -1;
    }

    if(position.x + radius * size >= 1.0F) {
        position.x = 1.0F - radius * size;
        velocity.x *= -1;
    }
    if(position.x - radius * size <= -1.0F) {
        position.x = -1.0F + radius * size;
        velocity.x *= -1;
    }
}

void Ball::Move(GLdouble dt)
{
    position.x += velocity.x * dt;
    if(position.x + radius * size >= 1.0F) {
        position.x = 1.0F - radius * size;
        velocity.x *= -1;
    } else if (position.x - radius * size <= -1.0F) {
        position.x = -1.0F + radius * size;
        velocity.x *= -1;
    }
    position.y += velocity.y * dt;
    if(position.y + radius * size >= 1.0F) {
        position.y = 1.0F - radius * size;
        velocity.y *= -1;
    } else if (position.y - radius * size <= -1.0F) {
        position.y = -1.0F + radius * size;
        velocity.y *= -1;
    }
}
void Ball::Draw()
{
    Config::UseCircle();
    transformation = glm::mat4(1.0F);
    transformation = glm::translate(transformation, position);

    Config::shader.SetUniform("transformation", transformation);

    glDrawElements(GL_TRIANGLE_FAN, 100 + 2, GL_UNSIGNED_SHORT, NULL);
}
void Paddle::Draw()
{
    Config::Use();
    transformation = glm::mat4(1.0F);
    transformation = glm::translate(transformation, position);
    transformation = glm::scale(transformation, size);
    
    Config::shader.SetUniform("transformation", transformation);

    glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_SHORT, NULL);
}
void Paddle::Scale(GLshort sign)
{
    size.x += sign * 0.02F;
    size.y += sign * 0.02F;
    if(size.x < 0.0F) size.x = 0.02F;
    else if(size.x >= 10.0F) size.x = 10.0F - 0.02F;
    
    if(size.y < 0.0F) size.y = 0.02F;
    else if(size.y >= 10.0F) size.y = 10.0F - 0.02F;

    if(position.x - size.x * width <= -1.0F) position.x = -1.0F + size.x * width;
    if(position.x + size.x * width >= 1.0F) position.x = 1.0F - size.x * width;

    if(position.y - size.y * height <= -1.0F) position.y = -1.0F + size.y * height;
    if(position.y + size.y * height >= 1.0F) position.y = 1.0F - size.y * height;
}
void Paddle::Move(GLshort x, GLshort y, GLshort z, GLdouble dt)
{
    // new movement on new key change 
    if(y and (velocity.y == 0.0F or (velocity.y < 0.0F and y > 0) or (velocity.y > 0.0F and y < 0))) {
        velocity.y = y * speed;
    }
    if(x and (velocity.x == 0.0F or (velocity.x < 0.0F and x > 0) or (velocity.x > 0.0F and x < 0))) {
        velocity.x = x * speed;
    }

    // if(Config::isPressed[Key::A]) {}

    if(!x and !y and !z) velocity.x = velocity.y = velocity.z = 0.0F;
    // else retain previous velocity and increase
    velocity.y += y * acceleration * dt;
    velocity.x += x * acceleration * dt;

    position.y += y ? velocity.y * dt : 0.0F;
    position.x += x ? velocity.x * dt : 0.0F;

    if(position.y + height * size.y >= 1.0F) position.y = 1.0F - height * size.y;
    if(position.y - height * size.y <= -1.0F) position.y = -1.0F + height * size.y;

    if(position.x + width * size.x >= 1.0F) position.x = 1.0F - width * size.x;
    if(position.x - width * size.x <= -1.0F) position.x = -1.0F + width * size.x;
}