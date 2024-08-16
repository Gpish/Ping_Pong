#include "../Headers/game.h"

GLdouble Game::timePrev = 0.0F;
GLdouble Game::timeNow = 0.0F;

int Game::Init()
{
    Config::Init();
    pad[0] = Paddle();
    pad[0].SetPosition(1.0F - pad[0].Width(), 0.0F, 0.0F);
    
    pad[1] = Paddle();
    pad[1].SetPosition(-1.0F + pad[1].Width(), 0.0F, 0.0F);

    ball = Ball();
    
    timePrev = Config::window.GetTime();
    timeNow = timePrev;

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // glClearColor(1.0F, 1.0F, 1.0F, 1.0F);
}

void Game::Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    pad[0].Draw(); 
    pad[1].Draw();
    ball.Draw();
}
int Game::ProcessEvents()           //dsadsa
{
    Config::window.ProcessEvents();     //poll events
    Config::window.SwapBuffers();
}
void Game::Update()
{
    timePrev = timeNow;
    timeNow = Config::window.GetTime();
    GLdouble dt = timeNow - timePrev;

    if (Config::isPressed[Config::Key::ESC]) {
        gameEnd = Config::isPressed[Config::Key::ESC];
        glfwSetWindowShouldClose(Config::window.GetWindowPointer(), GL_TRUE);
    }
    
    glm::ivec3 dir1(0, 0, 0), dir2(0, 0, 0);

    if(Config::isPressed[Config::Key::UP]) dir1.y = 1; //pad[0].Move(0, 1, 0, dt);
    else if(Config::isPressed[Config::Key::DOWN]) dir1.y = -1; //pad[0].Move(0, -1, 0, dt);
    else {} //pad[0].SetVerticalVelocity(0.0F);

    if(Config::isPressed[Config::Key::LEFT]) dir1.x = -1; //pad[0].Move(-1, 0, 0, dt);
    else if(Config::isPressed[Config::Key::RIGHT]) dir1.x = 1; //pad[0].Move(1, 0, 0, dt);
    else {} //pad[0].SetHorizontalVelocity(0.0F);

    if(Config::isPressed[Config::Key::W]) dir2.y = 1;  //pad[1].Move(0, 1, 0, dt);
    else if(Config::isPressed[Config::Key::S]) dir2.y = -1;  //pad[1].Move(0, -1, 0, dt);
    else {} //pad[1].SetVerticalVelocity(0.0F);

    if(Config::isPressed[Config::Key::D]) dir2.x = 1; //pad[1].Move(-1, 0, 0, dt);
    else if(Config::isPressed[Config::Key::A]) dir2.x = -1;  //pad[1].Move(1, 0, 0, dt);
    else {} //pad[1].SetHorizontalVelocity(0.0F);
    
    pad[0].Move(dir1.x, dir1.y, dir1.z, dt);
    pad[1].Move(dir2.x, dir2.y, dir2.z, dt);

    if(Config::isPressed[Config::Key::Z]) pad[0].Scale(-1);
    else if(Config::isPressed[Config::Key::X]) pad[0].Scale(1);
    // pad[0].Move(dt); 

    ball.Move(dt);
    gameEnd = ball.CheckCollision(pad[0], pad[1]);
}

void Game::Terminate()
{
    glfwTerminate();
}