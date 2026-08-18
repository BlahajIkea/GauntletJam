#include <raylib.h>
#include <string>
#include <iostream>

//-- Includes: 
#include "Player.hpp"
#include "Car.hpp"


// -- DEFINE --
#define SCRENHEIGHT 950
#define SCREANWIDTH 760

int main(void)
{
    
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "HELLO !!");
    Car car({0, 0}, 500);
    Car car1({500, 500}, -400);
    

    SetTargetFPS(60);

    while (!WindowShouldClose())    
    {   
        ClearBackground(RAYWHITE);
        car.Update();
        BeginDrawing();

        car.Draw();
        car1.Draw();
        car1.Update();
        EndDrawing();
    
    }
    CloseWindow();
}