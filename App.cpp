#include "./Headers/game.h"

int main()
{
    Game game;
    game.Init();

    while(!game.End()) {
        game.Update();
        game.Draw();
        game.ProcessEvents();
    }
    // assdadf D
    game.Terminate();
    return 0;
}