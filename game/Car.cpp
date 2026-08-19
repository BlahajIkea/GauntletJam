#include <iostream>

#include "Car.hpp"
#include "Player.hpp"

Player pl;


Car::Car(Vector2 spawnLocation, int moveSpeed) {
    m_sprite = LoadTexture("assets/blueMivi.png");
    m_moveSpeed = moveSpeed;
    m_position = spawnLocation;
    m_leftSpawnX = -500;
    isPlaying = true;
    
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
    if (m_position.x >= GetScreenWidth() + 75 || !pl.isAlive) {
        m_leftSpawnX = GetRandomValue(-150, -430);
        m_leftSpawnY = GetRandomValue(-0, 650);
        m_position.x = m_leftSpawnX;
        m_position.y = m_leftSpawnY;
    }
}