#include <raylib.h>
#include <string>
#include <iostream>

//-- Includes: 
#include "Player.hpp"
#include "Car.hpp"


// -- DEFINE --
#define SCRENHEIGHT 750
#define SCREANWIDTH 760

int main(void)
{
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "HELLO !!");
    
    Player player;
    Car car({0, 0}, 500);
    Car car1({500, 500}, -400);
    

    SetTargetFPS(60);

    while (!WindowShouldClose())    
    {   
        bool isColliding = CheckCollisionRecs(player.GetRect(), car.GetRect()); 

        ClearBackground(RAYWHITE);
        
        player.outOfBounds();
        player.Update();
        BeginDrawing();
        player.DrawHitbox(isColliding);

        player.Draw();
        car.Draw();
        car.Update();
        car.DrawHitbox(isColliding);


        car1.Draw();
        car1.Update();
        car1.DrawHitbox(false);
        EndDrawing();
    
    }
    CloseWindow();
}