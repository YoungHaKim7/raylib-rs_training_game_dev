#include <raylib-cpp.hpp>

#include "headers/game.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

int main()
{

    Color darkBlue = { 44, 44, 127, 255 };

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib C++ Tetris");

    SetTargetFPS(60);

    Game game = Game();

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here
        // Key handling
        game.HandleInput();

        // BlockDown
        if (EventTriggered(0.02)) {
            game.MoveBlockDown();
        }

        // Draw
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
