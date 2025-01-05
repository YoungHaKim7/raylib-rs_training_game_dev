#include <raylib-cpp.hpp>

#include "headers/game.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

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

        // Draw
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }

    CloseWindow();
}
