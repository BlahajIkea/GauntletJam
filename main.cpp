#include <raylib.h>

//-- Includes: 

#include "gameDefaultsSettings.hpp"
#include "player.hpp"

// -- DEFINE --
#define SCRENHEIGHT 800
#define SCREANWIDTH 800

bool movingUp;
bool movingDown;
bool isSprinting;

float playerMoveSpeed = 2;
float playerSprintSpeed = 4;

Texture2D playerSpriteAtlas;

void getPlayerInput() {
    if (IsKeyDown(KEY_UP)) {
        movingUp = true;
    } else  movingUp = false;

    if (IsKeyDown(KEY_DOWN)) {
        movingDown = true;
    } else  movingDown = false;

    if(IsKeyDown(KEY_SPACE))
        isSprinting = true;
    else
        isSprinting = false;
}


int main(void)
{
//  INTIALIZING STUFF
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "my game");
    Vector2 playerPos= { (float) SCREANWIDTH / 2, (float)SCRENHEIGHT / 2 };
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    playerSpriteAtlas = LoadTexture("assets/malay-sheet.png");




    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {    
        getPlayerInput();


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
        
            DrawCircleV(playerPos, 15, PINK);

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