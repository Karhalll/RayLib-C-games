#include "Character.h"

Character::Character(int winWidth, int winHeight)
{
    width = (float)texture.width / (float)maxFrames;
    height = (float)texture.height;
    screenPos = {
        static_cast<float>(winWidth) / 2.f - scale * (0.5f * width),
        static_cast<float>(winHeight) / 2.f - scale * (0.5f * height)};
}

void Character::tick(float deltaTime)
{

    worldPosLastFrame = worldPos;

    Vector2 direction{};
    Vector2 movement{};
    if (IsKeyDown(KEY_A))
        direction.x -= 1.f;
    if (IsKeyDown(KEY_D))
        direction.x += 1.f;
    if (IsKeyDown(KEY_W))
        direction.y -= 1.f;
    if (IsKeyDown(KEY_S))
        direction.y += 1.f;
    if (Vector2Length(direction) != 0.f)
    {
        direction = Vector2Normalize(direction);
        movement = Vector2Scale(direction, speed);

        worldPos = Vector2Add(worldPos, movement);
        direction.x < 0.f ? rightLeft = -1.f : rightLeft = 1.f;

        texture = run;
    }
    else
    {
        texture = idle;
    }

    // update animation frame
    runningTime += deltaTime;
    if (runningTime >= updateTime)
    {
        frame++;
        runningTime = 0.f;
        if (frame > maxFrames)
            frame = 0;
    }

    // draw the character
    Rectangle source{frame * width, 0.f, rightLeft * width, height};
    Rectangle dest{screenPos.x, screenPos.y, width * scale, height * scale};
    DrawTexturePro(texture, source, dest, Vector2{}, 0.f, WHITE);
}

void Character::undoMovement()
{
    worldPos = worldPosLastFrame;
}

Rectangle Character::GetCollisionRec()
{
    return Rectangle{
        screenPos.x,
        screenPos.y,
        width * scale,
        height * scale};
}