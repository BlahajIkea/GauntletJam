#include <raylib.h>
#include <string>
#include <iostream>

//-- Includes: 

#include "player.hpp"
#include "RedCar.hpp"
#include "BlueCar.hpp"


// -- DEFINE --
#define SCRENHEIGHT 950
#define SCREANWIDTH 760

Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;


Player player;
RedCar redCar;
BlueCar blueCar;

//MIVIS
//Texture2D blueMiviLeft;
Texture2D blueMiviRight;

Texture2D redMiviRight;

Rectangle blueCarHitbox {
   blueCar.carPos.x,
   blueCar.carPos.y,
   150,
   40,
};

Rectangle redCarHitbox {
   redCar.carPos.x,
   redCar.carPos.y,
   150,
   40,
};

Rectangle playerHitbox {
    player.playerPos.x / + player.playerPos.x,
    player.playerPos.y,
    25,
    120,
};




void InitCars(){
    // - RED CARS - LEFT SIDE

    redCar.carOutOfBoundsRange = 40;
    redCar.carPos.x = -400;
    redCar.carMoveSpeed = 500;
    redCar.leftSpawnX = -120;

    // - BLUE CARS - LEFT SIDE 
    blueCar.carOutOfBoundsRange = 40;
    blueCar.carPos.x = -430;
    blueCar.carMoveSpeed = 150;
    blueCar.leftSpawnX = -160;


    
    
}

void driveRedCarRight() {
    DrawRectangleRec(redCarHitbox, RAYWHITE); // HITBOX
    
    redCar.carPos.x += GetFrameTime() * redCar.carMoveSpeed;
    redCarHitbox.x = redCar.carPos.x;
    redCarHitbox.y = redCar.carPos.y + 35;
    DrawTextureV(redMiviRight, Vector2{redCar.carPos}, WHITE);
    if(redCar.carPos.x > GetScreenWidth() + redCar.carOutOfBoundsRange)
    {
        redCar.carPos.x = redCar.leftSpawnX;
        redCar.leftSpawnY = GetRandomValue(0, GetScreenHeight() / 0.7);
        redCar.carPos.y = redCar.leftSpawnY;
    }
}

void driveBueCarRight() {
    DrawRectangleRec(blueCarHitbox, RAYWHITE); // HITBOX
    
    blueCar.carPos.x += GetFrameTime() * blueCar.carMoveSpeed;
    blueCarHitbox.x = blueCar.carPos.x;
    blueCarHitbox.y = blueCar.carPos.y + 35;
    
    DrawTextureV(blueMiviRight, Vector2{blueCar.carPos}, WHITE);
    blueCar.carPos.x += GetFrameTime() * blueCar.carMoveSpeed;
    if(blueCar.carPos.x > GetScreenWidth() + blueCar.carOutOfBoundsRange)
    {
        blueCar.carPos.x = blueCar.leftSpawnX;
        blueCar.leftSpawnY = GetRandomValue(0, GetScreenHeight() / 0.5);
        blueCar.carPos.y = blueCar.leftSpawnY;
    }
}

void checkIfPlayeIsDead(){
    if (!player.isAlive)
        std::cout << "dead // collsion" << std::endl;
}


void flipSpriteUpDown() {
    if (player.isFacingDown)
        DrawTextureV(playerSpriteAtlasDown, (Vector2){player.playerPos}, WHITE);
    if (player.isFacingUp)
        DrawTextureV(playerSpriteAtlasUp, (Vector2){player.playerPos}, WHITE);
}

void getPlayerInput() {
    if (IsKeyDown(KEY_UP)) {
        player.movingUp = true;
        player.isFacingDown = false;
        player.isFacingUp = true;
    } else  player.movingUp = false;

    if (IsKeyDown(KEY_DOWN)) {
       player.movingDown = true;
        player.isFacingDown = true;
        player.isFacingUp = false;
    } else  player.movingDown = false;

    // if(IsKeyDown(KEY_SPACE))
    //     player.isSprinting = true;
    // else
    //     player.isSprinting = false;


    if (player.movingUp){player.playerPos.y -= GetFrameTime() * player.playerMoveSpeed;}
    if(player.movingDown) {player.playerPos.y += GetFrameTime() * player.playerMoveSpeed;}
}
            
void isPlayerOutOfBounds() {
    if (player.playerPos.y < 0) {
        player.playerPos.y = 0;
        player.playerPos.y = GetScreenHeight() - GetScreenHeight();
    }
    
    if (player.playerPos.y > GetScreenHeight() - 125) // CHECKS IF THE PLAYER SCORED !!!
    {
        player.playerPos.y = -15;
        player.playerPoints += 1;
        blueCar.carPos.x = blueCar.leftSpawnX;
        redCar.carPos.x = redCar.leftSpawnX;
    }
}

void drawPlayerHitBox() {
    playerHitbox.y = player.playerPos.y;
    playerHitbox.x = player.playerPos.x;
    DrawRectangleRec(playerHitbox, RAYWHITE);
}


void checkIfCollidingWithRedCar() {
    if (CheckCollisionRecs(playerHitbox, redCarHitbox)) {
        player.isAlive = false;
    }
    
}

void drawPointsToScreen() {
    DrawText(TextFormat("Level: %d", player.playerPoints), 0, 0, 25, BLACK);
}

int main(void)
{
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "Trafik");
    player.playerMoveSpeed = 200;
    player.playerPoints = 0;

    SetTargetFPS(60);             
    
    //player.isAlive = true;
    
    player.isFacingDown = true;
    player.playerPos.x = GetScreenWidth() / 2.5;
    player.playerPos.y = GetScreenHeight() - GetScreenHeight();
    
    //cars
    InitCars();
    //redMiviLeft = LoadTexture("assets/redMiviLeft.png");
    
    redMiviRight = LoadTexture("assets/redMiviRight.png");
    blueMiviRight = LoadTexture("assets/blueMiviRight.png");
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");
    
    // Main game loop
    while (!WindowShouldClose() && player.isAlive)    // Detect window close button or ESC key
    {   
        BeginDrawing();
            if (player.playerPoints > 0) {
                driveRedCarRight();
                driveBueCarRight();
            }

            getPlayerInput();
            isPlayerOutOfBounds();
            checkIfCollidingWithRedCar();
            drawPlayerHitBox();
            drawPointsToScreen();
            checkIfPlayeIsDead();
                ClearBackground(RAYWHITE);
                flipSpriteUpDown();
        EndDrawing();
    
    }

    UnloadTexture(redMiviRight);
    UnloadTexture(playerSpriteAtlasDown);
    UnloadTexture(playerSpriteAtlasUp);
    UnloadTexture(blueMiviRight);
    CloseWindow();
    return 0;
}

