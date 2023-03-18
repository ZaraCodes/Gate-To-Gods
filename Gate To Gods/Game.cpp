#include "Game.h"

Game::Game()
{
    playing = true;
    player = Player(20, 5, 1, 0.2f);
    player.SetPosition(Vector2(2, 5));

    level = Level();
    GridTile* starTile = level.GetTile(player.GetPosition());
    starTile->SetPlayer(&player);

    displayer = GameDisplayer(71, 19, &level, &player);
}

void Game::DoGameLoop()
{
    while (playing)
    {
        displayer.PrintScreen();
        DoPlayerTurn();
    }
}

void Game::DoPlayerTurn()
{
    std::string input = "";
    std::cin >> input;

    if (input.length() > 0) {
        switch (input[0])
        {
        case 'x':
            playing = false;
            break;
        case 'w':
            player.DoAction(&level, Vector2(0, -1));
            break;
        case 'a':
            player.DoAction(&level, Vector2(-1, 0));
            break;
        case 's':
            player.DoAction(&level, Vector2(0, 1));
            break;
        case 'd':
            player.DoAction(&level, Vector2(1, 0));
            break;
        default:
            break;
        }
    }
}

void Game::DoNPCTurn()
{

}
