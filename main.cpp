#include <raylib.h>
#include <string>
//-- Includes: 

#include "Player.hpp"
#include "Global_Game_Settings.hpp"

#include "Car.hpp"
#include "redCar.hpp"


// -- DEFINE --

Texture2D carSpriteAtlasLeft;
Texture2D carSpriteAtlasRight;
Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;

Player player;





void writeCords() {
    DrawText(std::to_string(player.playerPos.y).c_str(), 0, 0, 25, BLACK);
    DrawText(std::to_string(player.playerPos.x).c_str(), 0, 25, 25, BLACK);
}

void flipSpriteUpDown() {
    if (player.isFacingDown)
        DrawTextureV(playerSpriteAtlasDown, (Vector2){player.playerPos}, WHITE);
    if (player.isFacingUp)
        DrawTextureV(playerSpriteAtlasUp, (Vector2){player.playerPos}, WHITE);
}


void isPlayerDeadYet() {
    if (!player.isAlive) {

    }
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
      if (player.playerPos.y > 619) {
        player.playerPos.y = 620;
    }
}



int main(void)
{
    
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "my game");
    SetTargetFPS(60);             
    player.isFacingDown = true;
    player.isAlive = true;
    player.playerPos.x = GetScreenWidth() / 2;
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");
    carSpriteAtlasLeft = LoadTexture("assets/carGoingLeft.png");
    carSpriteAtlasRight = LoadTexture("assets/carGoingRight.png");



    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
        getPlayerInput();
        isPlayerOutOfBounds();

        
            
        BeginDrawing();
             //spawnRedCar();
             
            ClearBackground(RAYWHITE);
            flipSpriteUpDown();
            writeCords();
        EndDrawing();
 
    }

    CloseWindow();
 
    return 0;

}

