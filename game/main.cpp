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
    Car car({-300, 335}, 500);
    Car car1({-375, 323}, 400);
    Car car2({-302, 138}, 200);
    Car car3({-324, 363}, 200);
    Car car4({-305, 283}, 140);
    Car car5({-295, 283}, 180);
    

    SetTargetFPS(60);

    while (!WindowShouldClose())    
    {
        bool isColliding = CheckCollisionRecs(player.GetKillRect(), car.GetKillRect()); 
        bool isColliding1 = CheckCollisionRecs(player.GetKillRect(), car1.GetKillRect()); 
        bool isColliding2 = CheckCollisionRecs(player.GetKillRect(), car2.GetKillRect()); 
        bool isColliding3 = CheckCollisionRecs(player.GetKillRect(), car3.GetKillRect()); 
        bool isColliding4 = CheckCollisionRecs(player.GetKillRect(), car4.GetKillRect()); 
        bool isColliding5 = CheckCollisionRecs(player.GetKillRect(), car5.GetKillRect()); 
       
        car.RecallCars();
        car1.RecallCars();
        car2.RecallCars();
        car1.RecallCars();
        car4.RecallCars();
        car5.RecallCars();

        ClearBackground(BLACK);
        
        player.outOfBounds();
        player.Update();
        BeginDrawing(); // _____ BEGIN DRAWING _____
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
        
        car5.Draw();
        car5.Update();
        car5.DrawHitbox(isColliding5);
        

        EndDrawing();
    }
    CloseWindow();
}