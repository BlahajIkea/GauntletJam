#include <iostream>

#include "Car.hpp"
#include "Player.hpp"




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
    
    
    if(m_moveSpeed > 0)
        DrawTextureV(m_sprite, m_position, WHITE);
}

void Car::Update() {
     m_position.x += GetFrameTime() * m_moveSpeed;
}

Rectangle Car::GetKillRect() {
    return Rectangle{m_position.x + 110, m_position.y + 25, (float)m_sprite.width / 3, (float)m_sprite.height - 35};
}

void Car::DrawHitbox(bool isColliding) {
    Color outlineColour = isColliding ? BLACK : BLACK;
    DrawRectangleLinesEx(GetKillRect(), 3, outlineColour);
}


void Car::RecallCars() {
    if (m_position.x >= GetScreenWidth() + 75) {
        leftSpawnX = GetRandomValue(-150, -430);
        leftSpawnY = GetRandomValue(-0, 500);
        m_position.x = leftSpawnX;
        m_position.y = leftSpawnY;
       

    }
}