#include <raylib.h>
#include <string>
//-- Includes: 

#include "gameDefaultsSettings.hpp"
#include "player.hpp"

// -- DEFINE --
#define SCRENHEIGHT 800
#define SCREANWIDTH 800

bool movingUp;
bool movingDown;
bool isSprinting;

bool isFacingDown;
bool isFacingUp;

float playerMoveSpeed = 4;
float playerSprintSpeed = 4;

Vector2 playerPos= { 
        (float) SCREANWIDTH / 2.5 , 
        (float)SCRENHEIGHT / 2 
    };

Texture2D playerSpriteAtlasDown;
Texture2D playerSpriteAtlasUp;




void writeCords() {
    DrawText(std::to_string(playerPos.y).c_str(), 0, 0, 25, BLACK);
}

void flipSpriteUpDown() {
    if (isFacingDown)
        DrawTextureV(playerSpriteAtlasDown, (Vector2){playerPos}, WHITE);
    if (isFacingUp)
        DrawTextureV(playerSpriteAtlasUp, (Vector2){playerPos}, WHITE);
}

void getPlayerInput() {
    if (IsKeyDown(KEY_UP)) {
        movingUp = true;
        isFacingDown = false;
        isFacingUp = true;
    } else  movingUp = false;

    if (IsKeyDown(KEY_DOWN)) {
        movingDown = true;
        isFacingDown = true;
        isFacingUp = false;
    } else  movingDown = false;

    if(IsKeyDown(KEY_SPACE))
        isSprinting = true;
    else
        isSprinting = false;
}

void isPlayerOutOfBounds() {
    if (playerPos.y < 0) {
        playerPos.y = 0;
    }
      if (playerPos.y > 619) {
        playerPos.y = 620;
    }
}

int main(void)
{
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "my game");
    SetTargetFPS(60);             
    isFacingDown = true;
    
    playerSpriteAtlasDown = LoadTexture("assets/malayDown.png");
    playerSpriteAtlasUp = LoadTexture("assets/malayUp.png");
    




    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
        getPlayerInput();
        isPlayerOutOfBounds();

        if (movingUp){playerPos.y -= playerMoveSpeed;}
            
        if(movingDown) {playerPos.y += playerMoveSpeed;}
            
        if (movingUp && isSprinting) {
            playerPos.y -= playerMoveSpeed * playerSprintSpeed;
        }
            
        if(movingDown && isSprinting) {
            playerPos.y += playerMoveSpeed * playerSprintSpeed;
        }
            
        BeginDrawing();

            ClearBackground(RAYWHITE);
            flipSpriteUpDown();
            writeCords();

        EndDrawing();
 
    }


    CloseWindow();


    return 0;

}





/*
bool movingLeft;
    bool movingRight;


if (IsKeyDown(KEY_RIGHT)) 
        {
            movingRight = true;
        } else  movingRight = false;

        if (IsKeyDown(KEY_LEFT)) {
             movingLeft = true;
        } else  movingLeft = false;


        

        if (movingRight)
            playerPos.x += playerMoveSpeed;
        if(movingLeft)
            playerPos.x -= playerMoveSpeed;


        */