#include <raylib-cpp.hpp>

#include "blocks.cpp"
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

    TBlock block = TBlock();
    /* block.Move(4,3); */

    // Main game loop
    while (!w.ShouldClose()) // Detect window close button or ESC key
    {
        // Update

        // TODO: Update your variables here

        // Draw
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.Draw();
        block.Draw();

        EndDrawing();
    }

    return 0;
}
