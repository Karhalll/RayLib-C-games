#include "Enemy.h"
#include "raymath.h"



Enemy::Enemy(Vector2 pos, Texture2D idle_texture, Texture2D run_texture)
{
    worldPos = pos;
    texture = idle_texture;
    idle = idle_texture;
    run = run_texture;

    width = (float)texture.width / (float)maxFrames;
    height = (float)texture.height;

    speed = 3.f;
}

void Enemy::tick(float deltaTime)
{
    Vector2 toTarget = Vector2Subtract(target->getScreenPos(), screenPos);
    toTarget = Vector2Normalize(toTarget);
    toTarget = Vector2Scale(toTarget, speed);
    worldPos = Vector2Add(worldPos, toTarget);
    
    screenPos = Vector2Subtract(worldPos, target->getWorldPos());
    BaseCharacter::tick(deltaTime);
}
