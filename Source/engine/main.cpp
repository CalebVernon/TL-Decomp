// main.cpp
#include "raylib.h"

int main() {
    // Initialize the window
    const int screenWidth = 400;
    const int screenHeight = 240;
    InitWindow(screenWidth, screenHeight, "TL-Decomp PC Test");

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // Start drawing
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello TL-Decomp!", 100, 100, 20, LIGHTGRAY);

        EndDrawing();
    }

    // Close window and cleanup
    CloseWindow();

    return 0;
}
