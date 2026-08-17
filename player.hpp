#include "raylib.h"


class Player {

    public:
        bool movingUp;
        bool movingDown;
        bool isSprinting;

        bool isFacingDown;
        bool isFacingUp;

        float playerPos;
        float playerMoveSpeed = 4;
        float playerSprintSpeed = 4;


};