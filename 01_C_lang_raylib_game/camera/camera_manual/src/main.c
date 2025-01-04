#include "raylib.h"

#define MAX_BUIDINGS 100

int main(void)
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(800, 600, "2d camera raylib example");

    Rectangle player = { 400, 280, 40, 40 };
    Rectangle buildings[MAX_BUIDINGS] = { 0 };
    Color buildingsColor[MAX_BUIDINGS] = { 0 };

    int spacing = 0;

    for (int i = 0; i < MAX_BUIDINGS; i++) {
        // float // rust f32
        buildings[i].width = (float)GetRandomValue(50, 200);
        buildings[i].height = (float)GetRandomValue(100, 800);
        buildings[i].x = -6000.f + spacing;
        buildings[i].y = screenHeight - 130.0f - buildings[i].height;

        spacing += (int)buildings[i].width;

        buildingsColor[i] = (Color) { GetRandomValue(200, 240),
            GetRandomValue(200, 240), GetRandomValue(200, 250), 255 };
    }

    Camera2D camera = { 0 };
    camera.target = (Vector2) { player.x + 20.0f, player.y + 20.0f };
    camera.offset = (Vector2) { screenWidth / 2.0f, screenHeight / 2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60); // Set out game to run at 60 Frames-per-second

    // Main game loop
    while (!WindowShouldClose()) {

        // Update
        // Player Movement
        if (IsKeyDown(KEY_RIGHT))
            player.x += 2;
        else if (IsKeyDown(KEY_LEFT))
            player.x -= 2;

        // Camera target follows player
        camera.target = (Vector2) { player.x + 20, player.y + 20 };

        float rotation = 40.0f;

        // Camera rotation control
        if (IsKeyDown(KEY_A))
            camera.rotation--;
        else if (IsKeyDown(KEY_D))
            camera.rotation++;

        // Limit camera totation to 80 degrees (-40 to 40)
        /*if (camera.rotation > 40)*/
        /*    camera.rotation = 40;*/
        /*else if (camera.rotation < -40)*/
        /*    camera.rotation = -40;*/

        // Camera zoom controls
        camera.zoom += ((float)GetMouseWheelMove() * 0.05f);

        if (camera.zoom > 3.0f)
            camera.zoom = 3.0f;
        else if (camera.zoom < 0.1f)
            camera.zoom = 0.1f;

        // Camera reset (zoom and rotation)
        if (IsKeyPressed(KEY_R)) {
            camera.zoom = 1.0f;
            camera.rotation = 0.0f;
        }

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode2D(camera);

        DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

        for (int i = 0; i < MAX_BUIDINGS; i++)
            DrawRectangleRec(buildings[i], buildingsColor[i]);

        DrawRectangleRec(player, RED);

        DrawLine((int)camera.target.x, -screenHeight * 10, (int)camera.target.x,
            screenHeight * 10, GREEN);
        DrawLine(-screenWidth * 10, (int)camera.target.y, screenWidth * 10,
            (int)camera.target.y, GREEN);
        EndMode2D();

        DrawText("SCREEN AREA", 640, 10, 20, RED);

        DrawRectangle(0, 0, screenWidth, 5, RED);
        DrawRectangle(0, 5, 5, screenWidth - 10, RED);
        DrawRectangle(screenWidth - 5, 5, 5, screenHeight - 5, RED);
        DrawRectangle(0, screenHeight - 5, screenWidth, 5, RED);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
