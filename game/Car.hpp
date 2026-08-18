#pragma once
#include "raylib.h"

class Car {
    
    private:
        Texture2D sprite;
        void Draw();
        void Update();
    public:
        Vector2 carPos;
        int carMoveSpeed;

        bool isFromLeft;
        bool isFromRight;

        int leftSpawnX;
        int leftSpawnY;

        int rightSpawnX;
        int rightSpawnY;

        int carOutOfBoundsRange;

        int height;
};