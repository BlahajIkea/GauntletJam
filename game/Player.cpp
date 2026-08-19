#include "raylib.h"
#include "Player.hpp"
#include <iostream>
#include <math.h>


Player::Player(){
    
    points = 0;
    //m_spriteUp = LoadTexture("assets/malayUp.png");
    m_spriteDown = LoadTexture("assets/malayDown.png");
    m_playerMoveSpeed = 400;

    m_position.x = 150;
    m_position.y = 150;
}

Player::~Player() {
    UnloadTexture(m_spriteDown);
    UnloadTexture(m_spriteUp);
}

void Player::Draw() {
    //Rectangle rect = {m_position.x, m_position.y, (float)m_spriteDown.width, (float)m_spriteDown.height};
    
    DrawTexture(m_spriteDown, m_position.x, m_position.y, WHITE);
}

void Player::Update() {
    
    if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_RIGHT)) m_position.y += GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_UP) && IsKeyDown(KEY_LEFT)) m_position.y += GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_RIGHT)) m_position.y -= GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);
    if(IsKeyDown(KEY_DOWN) && IsKeyDown(KEY_LEFT)) m_position.y -= GetFrameTime() * m_playerMoveSpeed / std::sqrt(2);

    if(IsKeyDown(KEY_DOWN)) m_position.y += GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_UP)) m_position.y -= GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_RIGHT)) m_position.x += GetFrameTime() * m_playerMoveSpeed;
    if(IsKeyDown(KEY_LEFT)) m_position.x -= GetFrameTime() * m_playerMoveSpeed;
    
    if (m_position.y > GetScreenHeight()) {
        points += 1;
        m_position.y = GetScreenHeight() - GetScreenHeight();
        std::cout << points << std::endl;
    }
}

void Player::outOfBounds(){
    
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