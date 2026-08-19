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
    Car car({}, 500);
    Car car1({}, 400);
    Car car2({}, 200);
    Car car3({}, 200);
    Car car4({}, 140);
    

    SetTargetFPS(60);

    while (!WindowShouldClose())    
    {   
        bool isColliding = CheckCollisionRecs(player.GetRect(), car.GetRect()); 
        bool isColliding1 = CheckCollisionRecs(player.GetRect(), car1.GetRect()); 
        bool isColliding2 = CheckCollisionRecs(player.GetRect(), car1.GetRect()); 
        bool isColliding3 = CheckCollisionRecs(player.GetRect(), car1.GetRect()); 
        bool isColliding4 = CheckCollisionRecs(player.GetRect(), car1.GetRect()); 
       
        car.RecallCars();
        car1.RecallCars();
        car2.RecallCars();
        car1.RecallCars();
        car4.RecallCars();

        ClearBackground(BLACK);
        
        player.outOfBounds();
        player.Update();
        BeginDrawing();
        player.DrawHitbox(false);
        player.Draw();

    // ---------------------------CARS----------------------------------
        car.Draw();
        car.Update();
        car.DrawHitbox(isColliding);


        car1.Draw();
        car1.Update();
        car1.DrawHitbox(isColliding1);
        
        
        car2.Draw();
        car2.Update();
        car2.DrawHitbox(isColliding2);
 
        car3.Draw();
        car3.Update();
        car3.DrawHitbox(isColliding3);

        car4.Draw();
        car4.Update();
        car4.DrawHitbox(isColliding4);
        
        
        
        EndDrawing();
    }
    CloseWindow();
}