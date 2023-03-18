#include "raylib.h"
#include "raymath.h"

#include "Character.h"
#include "Prop.h"

int main()
{
    const int windowWidth{384};
    const int windowHeight{384};
    InitWindow(windowWidth, windowHeight, "Classy Clash");

    Texture2D mapTexture = LoadTexture("nature_tileset/OpenWorldMap24x24.png");
    Vector2 mapPos{0.f, 0.f};
    const float mapScale{4.f};
    Character knight{windowWidth, windowHeight};

    Prop props[2]{
        Prop{Vector2{600.f, 300.f}, LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f, 500.f}, LoadTexture("nature_tileset/Log.png")}};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        Vector2 knightPos = knight.getWorldPos();
        // draw the map
        mapPos = Vector2Scale(knightPos, -1.f);
        DrawTextureEx(mapTexture, mapPos, 0.f, mapScale, WHITE);
        // draw the props
        for (auto prop : props)
        {
            prop.Render(knightPos);
        }

        // check map bounds
        knight.tick(GetFrameTime());
        if (knightPos.x < 0.f ||
            knightPos.y < 0.f ||
            knightPos.x + windowWidth > mapTexture.width * mapScale ||
            knightPos.y + windowHeight > mapTexture.height * mapScale)
        {
            knight.undoMovement();
        }

        // check for collisions
        for (auto prop : props)
        {
            Rectangle knightRect = knight.GetCollisionRec();
            Rectangle propRect = prop.GetCollisionRec(knight.getWorldPos());
            bool isCollidingWithKnight = CheckCollisionRecs(propRect, knightRect);
            if (isCollidingWithKnight)
            {
                knight.undoMovement();
            }
        }

        EndDrawing();
    }
    CloseWindow();
}