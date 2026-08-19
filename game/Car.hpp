#pragma once
#include "raylib.h"

class Car {
    public:
        Car(Vector2 spawnLocation, int moveSpeed);
        ~Car();
        void Draw();
        void Update();
        Rectangle GetKillRect();
        void DrawHitbox(bool isColliding);
        void RecallCars();
        void ResetCars();
        bool isPlaying;

    private:
        Texture2D m_sprite;
        Vector2 m_position;
        int m_moveSpeed;
        int m_leftSpawnX;
        int m_leftSpawnY;
};