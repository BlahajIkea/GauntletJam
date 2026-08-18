#include "raylib.h"

class Car {
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