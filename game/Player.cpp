#include "raylib.h"
#include "Player.hpp"
#include <iostream>
#include <math.h>



Player::Player(){
   
    score = 0;
    //m_spriteUp = LoadTexture("assets/malayUp.png");
    m_spriteDown = LoadTexture("assets/malayDown.png");
    m_playerMoveSpeed = 400;
    isAlive = true;
    m_position.x = 150;
    m_position.y = 150;
}

Player::~Player() {
    UnloadTexture(m_spriteDown);
    UnloadTexture(m_spriteUp);
}

void Player::Draw() {
    if (isAlive)
        DrawTexture(m_spriteDown, m_position.x, m_position.y, WHITE);
}

void Player::Update() {
    if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT) && isAlive) m_position.y += GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT) && isAlive) m_position.y += GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT) && isAlive) m_position.y -= GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT) && isAlive) m_position.y -= GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);

    if(IsKeyDown(KEY_DOWN) && isAlive) m_position.y += GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_UP) && isAlive) m_position.y -= GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_RIGHT) && isAlive) m_position.x += GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_LEFT)&& isAlive) m_position.x -= GetFrameTime() * m_playerMoveSpeed;
}

void Player::OutOfBounds(){
    //top
    if(m_position.y <= GetScreenHeight() - GetScreenHeight()) {
        m_position.y = -5;
        std::cout << "TOP" << std::endl;
    }

    if(m_position.x <= GetScreenWidth() - GetScreenWidth()) {
        std::cout << "LEFT" << std::endl;
        m_position.x = 750;
    }

    if(m_position.x >= GetScreenWidth()) {
        std::cout << "RIGHT" << std::endl;
        m_position.x = -5;
    }

}

Rectangle Player::GetKillRect() {
    return Rectangle{m_position.x, m_position.y, (float)m_spriteDown.width /2 , (float)m_spriteDown.height};
}

void Player::DrawHitbox(bool isColliding) {
    Color outLineColour = isColliding ? RED : RAYWHITE;
    DrawRectangleLinesEx(GetKillRect(), 3, outLineColour);
   
}
void Player::DrawScore(){
    DrawText(TextFormat("Score: %d", score), 0, 0, 25, WHITE);
    DrawText(TextFormat("Dead?: %d", isAlive), 0, 25, 25, WHITE);
}

void Player::DrawFinalScore(){
    finalScore = score;
}

void Player::GainPoints() {
     if (m_position.y > GetScreenHeight() && isAlive) {
        score += 1;
        m_position.y = GetScreenHeight() - GetScreenHeight();
        std::cout << score << std::endl;
    }
}

void Player::RotateThePlayerAfterDeath() {
    Rectangle source = (Rectangle) {0, 0, 0, 0};
    Rectangle dest = (Rectangle) {0, 0, 0, 0};
    if(!isAlive) {
        DrawTexturePro(m_spriteDown, source, dest, (Vector2) {m_position.x, m_position.y}, 45, WHITE);
    }
}