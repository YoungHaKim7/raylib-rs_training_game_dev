#include "raylib.h"

int main(void) {
    InitWindow(800, 600, "raylib [core] example - basic window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, DARKGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
