#include <iostream>
#include <string>
#include "Game.h"
/// <summary>This is were the game's execution starts.</summary>
/// <returns>termination code</returns>
int main()
{
    Game* game = new Game();
    game->DoGameLoop();
    delete game;
    game = nullptr;
}
