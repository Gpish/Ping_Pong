#ifndef PADDLE
#define PADDLE

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

#include "config.h"

#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/glm.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/matrix_transform.hpp"
#include "/Users/IGupta/playground/Includes/glm-0.9.9.8/glm/gtc/type_ptr.hpp"

class Paddle;
class Ball : public Config {
        public:
                GLfloat radius;
                glm::mat4 transformation;
                glm::vec3 position, velocity;
                GLfloat speed, size;
                GLfloat g;
                Ball() : g(-0.9F), radius(0.05F), transformation(glm::mat4(1.0F)), position(glm::vec3(0.0F)), velocity(glm::vec3(1.6F, -0.3F, 0.0F)), size(1.0F) {}
                void Move(GLdouble dt = 1.0F);
                void Bounce(GLdouble dt);
                bool CheckCollision(const Paddle &p1, const Paddle &p2);
                void Draw();

};

// glm::mat4 transformation;
class Paddle : public Config{
        private:
        protected:
        public:
                GLfloat height, width;
                GLdouble acceleration;
                glm::mat4 transformation;
                glm::vec3 position, velocity, size;
                GLfloat speed;
                Paddle(GLfloat x = 0.0F, GLfloat y = 0.0F, GLfloat z = 0.0F) : height(0.1F), size(glm::vec3(1.0F, 1.0F, 1.0F)), width(0.05F), speed(0.3F), acceleration(0.2F), position(glm::vec3(x, y, z)), velocity(glm::vec3(0.0F)) {}
                void SetPosition(GLfloat x, GLfloat y, GLfloat z) { position = glm::vec3(x, y, z); }
                void SetVerticalVelocity(GLfloat vy) { velocity.y = vy; }
                void SetHorizontalVelocity(GLfloat vx) { velocity.x = vx; }
                GLfloat Width() { return width; }
                GLfloat Speed() { return speed; }
                void Draw();
                void Move(GLshort x = 0, GLshort y = 0, GLshort = 0, GLdouble dt = 0.0F);
                // void Move(glm::vec3 dir, GLdouble dt = 0.0F);
                void Scale(GLshort sign);
};

#endif