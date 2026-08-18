#include <iostream>

#include "Car.hpp"


Car::Car(Vector2 spawnLocation, int moveSpeed) {
    m_sprite = LoadTexture("assets/blueMivi.png");
    m_moveSpeed = moveSpeed;
    m_position = spawnLocation;

    rightSpawn = 500;
    leftSpawn = -500;
    
};

Car::~Car() {
    UnloadTexture(m_sprite);
};

void Car::Draw() {
    if (m_moveSpeed < 0) {
        Rectangle rect = {0, 0, (float)-m_sprite.width,  (float)m_sprite.height,};
        DrawTextureRec(m_sprite, rect, m_position, WHITE);
    }
    else
        DrawTextureV(m_sprite, m_position, WHITE);
    
    if (m_position.x > GetScreenWidth() + 150) {
        m_position.x = leftSpawn - 500;
    }

    if (m_sprite.width < 0 && m_position.x > GetScreenWidth() - 150) {
        m_position.x = leftSpawn - 500;
        std::cout << "TEST" << std::endl;
    }



}
void Car::Update() {
     m_position.x += GetFrameTime() * m_moveSpeed;
}