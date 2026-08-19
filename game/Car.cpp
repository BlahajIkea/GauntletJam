#include <iostream>

#include "Car.hpp"

Car::Car(Vector2 spawnLocation, int moveSpeed) {
    m_sprite = LoadTexture("assets/blueMivi.png");
    m_moveSpeed = moveSpeed;
    m_position = spawnLocation;
    leftSpawnX = -500;
    
};

Car::~Car() {
    UnloadTexture(m_sprite);
};

void Car::Draw() {
    if (m_moveSpeed < 0) {
        Rectangle flipSpriteRect = {0, 0, (float)-m_sprite.width,  (float)m_sprite.height,};
        DrawTextureRec(m_sprite, flipSpriteRect, m_position, WHITE);
        DrawRectangleLinesEx(flipSpriteRect, 5, BLACK);
    }
    else
        DrawTextureV(m_sprite, m_position, WHITE);
}

void Car::Update() {
     m_position.x += GetFrameTime() * m_moveSpeed;
}

Rectangle Car::GetRect() {
    return Rectangle{m_position.x, m_position.y, (float)m_sprite.width, (float)m_sprite.height};
}

void Car::DrawHitbox(bool isColliding) {
    Color outlineColour = isColliding ? RED : RAYWHITE;
    DrawRectangleLinesEx(GetRect(), 3, outlineColour);
}

void Car::RecallCars() {
     if (m_position.x >= GetScreenWidth() + 75) {
        m_position.x = leftSpawnX;
        std::cout << "one car" << std::endl;
    }
}