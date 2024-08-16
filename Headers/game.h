#ifndef GAME
#define GAME

#include "config.h"
#include "paddle.h"

#include <cstdlib>

class Game : public Config{
    private:
            Paddle pad[2];
            Ball ball;
            static GLdouble timePrev;
            static GLdouble timeNow;
            bool gameEnd;
        //     void DrawScene(const Config &config);
    public:
            Game() : Config(), gameEnd(false) {}
            int Init();
            int End() { return Config::window.Close() or gameEnd; }
            void Draw();
            void Update();          // pad.Move(dt, direction) set uniform
            int ProcessEvents();    // PollEvents will call KeyCallbackFunc
            void Terminate();
};

#endif

