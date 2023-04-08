#include <iostream>
#include <string>
#include "Game.h"

#ifdef _WIN32
#include <Windows.h>
#endif

static HANDLE stdoutHandle;
static DWORD outModeInit;

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif

/// <summary>
/// Enables the console to correctly interpret ANSI escape codes.
/// I joinked this from: https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
/// </summary>
void SetupConsole() {
    DWORD outMode = 0;
    stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (stdoutHandle == INVALID_HANDLE_VALUE) exit(GetLastError());
    if (!GetConsoleMode(stdoutHandle, &outMode)) exit(GetLastError());

    outModeInit = outMode;

    // enable ANSI escape codes
    outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

    if (!SetConsoleMode(stdoutHandle, outMode)) exit(GetLastError());
}

/// <summary>
/// Resets the console.
/// I joinked this from: https://solarianprogrammer.com/2019/04/08/c-programming-ansi-escape-codes-windows-macos-linux-terminals/
/// </summary>
void RestoreConsole() {
    std::cout << "\x1b[0m";

    if (!SetConsoleMode(stdoutHandle, outModeInit)) exit(GetLastError());
}

/// <summary>This is were the game's execution starts.</summary>
/// <returns>termination code</returns>
int main()
{
    SetupConsole();

    Game* game = new Game();
    game->DoGameLoop();
    delete game;
    game = nullptr;

    RestoreConsole();
}
