#include <raylib.h>
#include <string>
#include <iostream>

//-- Includes: 

#include "player.hpp"
#include "RedCar.hpp"
#include "BlueCar.hpp"


// -- DEFINE --
#define SCRENHEIGHT 600
#define SCREANWIDTH 760

Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;

//MIVIS
//Texture2D blueMiviLeft;
Texture2D blueMiviRight;



//Texture2D redMiviLeft;
Texture2D redMiviRight;


Rectangle playerHitbox;

Player player;
RedCar redCar;
BlueCar blueCar;


void InitCars(){
    // - RED CARS - LEFT SIDE

    redCar.carOutOfBoundsRange = 40;
    redCar.carPos.x = -400;
    redCar.carMoveSpeed = 10;
    redCar.leftSpawnX = -120;

    // - BLUE CARS - LEFT SIDE 
    blueCar.carOutOfBoundsRange = 40;
    blueCar.carPos.x = -430;
    blueCar.carMoveSpeed = 5;
    blueCar.leftSpawnX = -160;
}

void driveRedCarRight() {
    DrawTextureV(redMiviRight, Vector2{redCar.carPos}, WHITE);
    redCar.carPos.x += redCar.carMoveSpeed;
    if(redCar.carPos.x > GetScreenWidth() + redCar.carOutOfBoundsRange)
    {
        redCar.carPos.x = redCar.leftSpawnX;
        redCar.leftSpawnY = GetRandomValue(0, GetScreenHeight() / 0.7);
        redCar.carPos.y = redCar.leftSpawnY;
    }
}

void driveBueCarRight() {
    DrawTextureV(blueMiviRight, Vector2{blueCar.carPos}, WHITE);
    blueCar.carPos.x += blueCar.carMoveSpeed;
    if(blueCar.carPos.x > GetScreenWidth() + blueCar.carOutOfBoundsRange)
    {
        blueCar.carPos.x = blueCar.leftSpawnX;
        blueCar.leftSpawnY = GetRandomValue(0, GetScreenHeight() / 0.5);
        blueCar.carPos.y = blueCar.leftSpawnY;
    }
}


void checkIfPlayeIsDead(){
    if (!player.isAlive)
        std::cout << "dead" << std::endl;
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


    if (player.movingUp){player.playerPos.y -= player.playerMoveSpeed;}
    if(player.movingDown) {player.playerPos.y += player.playerMoveSpeed;}
    if (player.movingUp && player.isSprinting) {player.playerPos.y -= player.playerMoveSpeed * player.playerSprintSpeed;}
    if(player.movingDown && player.isSprinting) { player.playerPos.y += player.playerMoveSpeed * player.playerSprintSpeed;}
}
            
void isPlayerOutOfBounds() {
    if (player.playerPos.y < 0) {
        player.playerPos.y = 0;
    }
      if (player.playerPos.y > GetScreenHeight() - 125) {
        player.playerPos.y = GetScreenHeight() -125;
    }
}


void drawPlayerHitbox() {
    DrawRectangleRec(playerHitbox, WHITE);
}


int main(void)
{
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "Trafik");
    
    SetTargetFPS(60);             
    player.isAlive = true;
    player.isFacingDown = true;
    player.playerPos.x = GetScreenWidth() / 2.5;
    player.playerPos.y = GetScreenWidth() / 2.5;
    
    
    //cars
    InitCars();
    //redMiviLeft = LoadTexture("assets/redMiviLeft.png");
    
    redMiviRight = LoadTexture("assets/redMiviRight.png");
    
    
    blueMiviRight = LoadTexture("assets/blueMiviRight.png");
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");
    

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {   
            driveRedCarRight();
            driveBueCarRight();
            getPlayerInput();
            isPlayerOutOfBounds();
            playerHitbox = {player.playerPos.x, player.playerPos.y, 50, 100};
            checkIfPlayeIsDead();
            
        
    
        BeginDrawing();
                ClearBackground(RAYWHITE);
                flipSpriteUpDown();
        EndDrawing();
    
    }

    
    

    UnloadTexture(redMiviRight);
    CloseWindow();
    return 0;
}

