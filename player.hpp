#include "raylib.h"


class Player {

    public:
        bool movingUp;
        bool movingDown;
        bool isSprinting;

        bool isFacingDown;
        bool isFacingUp;
        bool isAlive;

        Vector2 playerPos;
        float playerMoveSpeed = 4;
        float playerSprintSpeed = 4;


};