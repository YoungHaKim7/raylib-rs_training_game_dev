#include <raylib-cpp.hpp>

#include "headers/game.h"
#include "headers/color.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 700

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

    Font font = LoadFontEx("assets/font/monogram.ttf", 64, 0, 0);

    Game game = Game();

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here
        // Key handling
        game.HandleInput();

        // BlockDown
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        // Draw
        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
