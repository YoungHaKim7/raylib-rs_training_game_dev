#include <raylib-cpp.hpp>
#include "headers/grid.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main()
{

    Color darkBlue = { 44, 44, 127, 255 };

    raylib::Color textColor(LIGHTGRAY);
    raylib::Window w(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib C++ Tetris");

    SetTargetFPS(60);

    Grid grid = Grid();
    grid.Print();

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(darkBlue);

        textColor.DrawText(
            "Congrats! You created your first window!", 190, 200, 20);
        EndDrawing();
    }

    return 0;
}
