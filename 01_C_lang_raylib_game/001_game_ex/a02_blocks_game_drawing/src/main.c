/*******************************************************************************************
*
*   PROJECT:        BLOCKS GAME
*   LESSON 02:      basic drawing
*   DESCRIPTION:    Basic shapes drawing (lines, circles, rectangles)
*
*   COMPILATION (Windows - MinGW):
*       gcc -o $(NAME_PART).exe $(FILE_NAME) -lraylib -lopengl32 -lgdi32 -lwinmm -Wall -std=c99
*
*   COMPILATION (Linux - GCC):
*       gcc -o $(NAME_PART).exe $(FILE_NAME) -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
*
*   Example originally created with raylib 2.0, last time updated with raylib 4.2

*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2017-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

//----------------------------------------------------------------------------------
// Useful values definitions
//----------------------------------------------------------------------------------
// clang-format off
#define PLAYER_LIFES             5
#define BRICKS_LINES             5
#define BRICKS_PER_LINE         20

#define BRICKS_POSITION_Y       50
// clang-format on

//----------------------------------------------------------------------------------
// Types and Structures Definition
//----------------------------------------------------------------------------------

// LESSON 01: Window initialization and screens management
typedef enum GameScreen { LOGO,
    TITLE,
    GAMEPLAY,
    ENDING } GameScreen;

// Player structure
typedef struct Player {
    Vector2 position;
    Vector2 speed;
    Vector2 size;
    Rectangle bounds;
    int lifes;
} Player;

// Ball structure
typedef struct Ball {
    Vector2 position;
    Vector2 speed;
    float radius;
    bool active;
} Ball;

// Bricks structure
typedef struct Brick {
    Vector2 position;
    Vector2 size;
    Rectangle bounds;
    int resistance;
    bool active;
} Brick;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    // LESSON 01: Window initialization and screens management
    InitWindow(screenWidth, screenHeight, "PROJECT: BLOCKS GAME");

    // NOTE: Load resources (textures, fonts, audio) after Window initialization

    // Game required variables
    GameScreen screen = LOGO; // Current game screen state

    int framesCounter = 0; // General pourpose frames counter
    int gameResult = -1; // Game result: 0 - Loose, 1 - Win, -1 - Not defined
    bool gamePaused = false; // Game paused state toggle

    // NOTE: Check defined structs on top
    Player player = { 0 };
    Ball ball = { 0 };
    Brick bricks[BRICKS_LINES][BRICKS_PER_LINE] = { 0 };

    // Initialize player
    player.position = (Vector2) { screenWidth / 2, screenHeight * 7 / 8 };
    player.speed = (Vector2) { 8.0f, 0.0f };
    player.size = (Vector2) { 100, 24 };
    player.lifes = PLAYER_LIFES;

    // Initialize ball
    ball.radius = 10.0f;
    ball.active = false;
    ball.position = (Vector2) { player.position.x + player.size.x / 2, player.position.y - ball.radius * 2 };
    ball.speed = (Vector2) { 4.0f, 4.0f };

    // Initialize bricks
    for (int j = 0; j < BRICKS_LINES; j++) {
        for (int i = 0; i < BRICKS_PER_LINE; i++) {
            bricks[j][i].size = (Vector2) { screenWidth / BRICKS_PER_LINE, 20 };
            bricks[j][i].position = (Vector2) { i * bricks[j][i].size.x, j * bricks[j][i].size.y + BRICKS_POSITION_Y };
            bricks[j][i].bounds = (Rectangle) { bricks[j][i].position.x, bricks[j][i].position.y, bricks[j][i].size.x, bricks[j][i].size.y };
            bricks[j][i].active = true;
        }
    }

    SetTargetFPS(60); // Set desired framerate (frames per second)
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        switch (screen) {
        case LOGO: {
            // Update LOGO screen data here!

            framesCounter++;

            if (framesCounter > 180) {
                screen = TITLE; // Change to TITLE screen after 3 seconds
                framesCounter = 0;
            }

        } break;
        case TITLE: {
            // Update TITLE screen data here!

            framesCounter++;

            // LESSON 03: Inputs management (keyboard, mouse)
            if (IsKeyPressed(KEY_ENTER))
                screen = GAMEPLAY;

        } break;
        case GAMEPLAY: {
            // Update GAMEPLAY screen data here!

            if (!gamePaused) {
                // TODO: Gameplay logic
            }

        } break;
        case ENDING: {
            // Update END screen data here!

            framesCounter++;

            // LESSON 03: Inputs management (keyboard, mouse)
            if (IsKeyPressed(KEY_ENTER)) {
                // Replay / Exit game logic
                screen = TITLE;
            }

        } break;
        default:
            break;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        switch (screen) {
        case LOGO: {
            // Draw LOGO screen here!

            DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);

        } break;
        case TITLE: {
            // Draw TITLE screen here!

            DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);

            if ((framesCounter / 30) % 2 == 0)
                DrawText("PRESS [ENTER] to START", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] to START", 20) / 2, GetScreenHeight() / 2 + 60, 20, DARKGRAY);

        } break;
        case GAMEPLAY: {
            // Draw GAMEPLAY screen here!

            // LESSON 02: Draw basic shapes (circle, rectangle)
            DrawRectangle(player.position.x, player.position.y, player.size.x, player.size.y, BLACK); // Draw player bar
            DrawCircleV(ball.position, ball.radius, MAROON); // Draw ball

            // Draw bricks
            for (int j = 0; j < BRICKS_LINES; j++) {
                for (int i = 0; i < BRICKS_PER_LINE; i++) {
                    if (bricks[j][i].active) {
                        if ((i + j) % 2 == 0)
                            DrawRectangle(bricks[j][i].position.x, bricks[j][i].position.y, bricks[j][i].size.x, bricks[j][i].size.y, GRAY);
                        else
                            DrawRectangle(bricks[j][i].position.x, bricks[j][i].position.y, bricks[j][i].size.x, bricks[j][i].size.y, DARKGRAY);
                    }
                }
            }

            // Draw GUI: player lives
            for (int i = 0; i < player.lifes; i++)
                DrawRectangle(20 + 40 * i, screenHeight - 30, 35, 10, LIGHTGRAY);

            // Draw pause message when required
            if (gamePaused)
                DrawText("GAME PAUSED", screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, screenHeight / 2 + 60, 40, GRAY);

        } break;
        case ENDING: {
            // Draw END screen here!

            DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);

            if ((framesCounter / 30) % 2 == 0)
                DrawText("PRESS [ENTER] TO PLAY AGAIN", GetScreenWidth() / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, GetScreenHeight() / 2 + 80, 20, GRAY);

        } break;
        default:
            break;
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------

    // NOTE: Unload any loaded resources (texture, fonts, audio)

    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
