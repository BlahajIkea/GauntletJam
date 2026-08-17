#include "raylib.h"

class Car {
   
    public:
        Vector2 carPos;
        int randomSpawnPos;
        int carLeftSpawn;
        int carMoveSpeed;
        bool isFromLeft;
        bool isFromRight;
};