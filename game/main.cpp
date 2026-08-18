#include <raylib.h>
#include <string>
#include <iostream>

//-- Includes: 

#include "player.hpp"
#include "RedCar.hpp"


// -- DEFINE --
#define SCRENHEIGHT 600
#define SCREANWIDTH 760

Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;

//MIVIS
Texture2D blueMiviLeft;
Texture2D blueMiviRight;

Texture2D redMiviLeft;
Texture2D redMiviRight;


Player player;
RedCar redCar;





void InitCars(){
    redCar.carOutOfBoundsRange = 130;

    //redcars
    
    redCar.carPos.x = redCar.leftSpawnX;
    redCar.carMoveSpeed = 5;
    redCar.leftSpawnX = -120;
}


void driveRedCar() {
    DrawTextureV(redMiviRight, Vector2{redCar.carPos}, WHITE);
    redCar.carPos.x += redCar.carMoveSpeed;
    if(redCar.carPos.x > GetScreenWidth() + redCar.carOutOfBoundsRange)
    {
        redCar.carPos.x = redCar.leftSpawnX;
        redCar.leftSpawnY = GetRandomValue(0, GetScreenHeight() / .5);
        redCar.carPos.y = redCar.leftSpawnY;
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

    if(IsKeyDown(KEY_SPACE))
        player.isSprinting = true;
    else
        player.isSprinting = false;


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
    redMiviLeft = LoadTexture("assets/redMiviLeft.png");
    redMiviRight = LoadTexture("assets/redMiviRight.png");
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");










    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
        driveRedCar();
        getPlayerInput();
        isPlayerOutOfBounds();
        
        checkIfPlayeIsDead();
        
        
        
        BeginDrawing();
    

        if (!player.isAlive) {
            DrawText("DEAD", 0, 0, 25, RED);

        }

            ClearBackground(BLACK);
            flipSpriteUpDown();
        EndDrawing();
 
    }
    CloseWindow();
    return 0;
}

