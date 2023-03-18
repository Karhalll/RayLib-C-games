#include "raylib.h"

int main()
{
    int windowWidth{900};
    int windowHeight{600};
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");

    const int width{50};
    const int height{80};

    int posY{windowHeight - height};
    int velocity {0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (IsKeyPressed(KEY_SPACE))
        {
            velocity -= 1;
        }
        
        posY += velocity;

        DrawRectangle(windowWidth/2, posY, width, height, BLUE);

        EndDrawing();
    }
    CloseWindow();
}