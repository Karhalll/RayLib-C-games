#include "raylib.h"
int main()
{
    int width = 350;
    int height = 300;
    InitWindow(width, height, "Axe Game");

    int circle_x{175};
    int circle_y{150};
    int circle_radius{25};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(circle_x, circle_y, circle_radius, BLUE);
        DrawRectangle(300, 0, 50, 50, RED);

        if (IsKeyDown(KEY_D) && circle_x + circle_radius < width)
        {
            circle_x = circle_x + 10;
        }

        if (IsKeyDown(KEY_A) && circle_x - circle_radius > 0)
        {
            circle_x -= 10;
        }

        EndDrawing();
    }
    
}