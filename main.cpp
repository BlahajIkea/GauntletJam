#include <raylib.h>
#include <string>
//-- Includes: 

#include "player.hpp"

// -- DEFINE --
#define SCRENHEIGHT 800
#define SCREANWIDTH 700



Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;

Player player;

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
       player. movingDown = true;
        player.isFacingDown = true;
        player.isFacingUp = false;
    } else  player.movingDown = false;

    if(IsKeyDown(KEY_SPACE))
        player.isSprinting = true;
    else
        player.isSprinting = false;
}

void isPlayerOutOfBounds() {
    if (player.playerPos.y < 0) {
        player.playerPos.y = 0;
    }
      if (player.playerPos.y > 619) {
        playerPos.y = 620;
    }
}

int main(void)
{
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "my game");
    SetTargetFPS(60);             
    player.isFacingDown = true;
    
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");
  

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
        getPlayerInput();
        isPlayerOutOfBounds();

        if (player.movingUp){player.playerPos.y -= player.playerMoveSpeed;}
        if(player.movingDown) {player.playerPos.y += player.playerMoveSpeed;}
        if (player.movingUp && player.isSprinting) {player.playerPos.y -= player.playerMoveSpeed * player.playerSprintSpeed;}
        if(player.movingDown && player.isSprinting) { player.playerPos.y += player.playerMoveSpeed * player.playerSprintSpeed;}
            
        BeginDrawing();
            ClearBackground(RAYWHITE);
            flipSpriteUpDown();
    
            writeCords();

        EndDrawing();
 
    }


    CloseWindow();


    return 0;

}

