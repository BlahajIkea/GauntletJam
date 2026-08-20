#include "raylib.h"
#include "Player.hpp"
#include <iostream>
#include <math.h>

#include "Car.hpp"

Player::Player(){
    
    //InitAudioDevice();
    m_UiPos.y = -35;
    finalScore = 0;
    score = 0;
    //m_spriteUp = LoadTexture("assets/malayUp.png");
    m_spriteDown = LoadTexture("assets/malayDown.png");
    m_spriteDead = LoadTexture("assets/malayDead.png");
    m_mainMenuSprite = LoadTexture("assets/avaragePedestrian.png");
    
    m_coinPickup = LoadSound("assets/pickupCoin.wav");
    m_dieSfx = LoadSound("assets/hitHurt.wav");
    m_playerTpSfx = LoadSound("assets/tpSfx.wav");

    m_playerMoveSpeed = 400;
    isAlive = true;
    m_position.x = GetScreenHeight()/ 2;
    m_position.y = GetScreenWidth()/ 2;
}

Player::~Player() {
    UnloadTexture(m_spriteDown);
    UnloadTexture(m_spriteDead);
    UnloadTexture(m_mainMenuSprite);

    UnloadSound(m_coinPickup);
    UnloadSound(m_playerTpSfx);
    UnloadSound(m_dieSfx);
    //CloseAudioDevice();
}

void Player::Draw() {
    if (isAlive)
        DrawTexture(m_spriteDown, m_position.x, m_position.y, WHITE);
    else {
        DrawTexture(m_spriteDead, m_position.x, m_position.y, WHITE);

        goToHospital += 1 *GetFrameTime();
        
        if(goToHospital > 10) {
            
        }
    }
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
        PlaySound(m_playerTpSfx);
    }

    if(m_position.x <= GetScreenWidth() - GetScreenWidth()) {
        std::cout << "LEFT" << std::endl;
        m_position.x = 750;
        PlaySound(m_playerTpSfx);
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
    Color outLineColour = isColliding ? BLACK : BLACK;
    DrawRectangleLinesEx(GetKillRect(), 3, outLineColour);
   
}
void Player::DrawScore(){
    DrawText(TextFormat("Score: %d", score), 0, 0, 25, WHITE);
    DrawText(TextFormat("High Score: %d", finalScore), 0, 25, 25, WHITE);
    //DrawText(TextFormat("amount of retries: %d", amountOfRetries), 0, 50, 25, WHITE);
    //DrawText(TextFormat("Dead?: %d", isAlive), 0, 750, 25, WHITE);
}


void Player::GainPoints() {
     if (m_position.y > GetScreenHeight() && isAlive) {
        score += 1;
        m_position.y = GetScreenHeight() - GetScreenHeight();
        std::cout << score << std::endl;
        PlaySound(m_coinPickup);
    }
}

void Player::StartingUI() {
    if (m_UiPos.y <= 2000 && !isAlive) {
        m_UiPos.y += 80 * GetFrameTime();
        DrawTextureV(m_mainMenuSprite, Vector2{m_UiPos.x, m_UiPos.y}, WHITE);
    }
}

void Player::RespawnPlayer() {
    if(IsKeyPressed(KEY_ENTER) && !isAlive) {
            isAlive = true;
            finalScore = score;
            score = 0;
            m_position.y = GetScreenHeight() - 15;
        }
}
