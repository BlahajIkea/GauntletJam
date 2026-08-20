#include <raylib.h>
#include <string>
#include <iostream>


//-- Includes: 
#include "Player.hpp"
#include "Car.hpp"


// -- DEFINE --
#define SCRENHEIGHT 750
#define SCREANWIDTH 760

Player player;
bool gameHasStarted = true;




int main(void) {
    InitWindow(SCREANWIDTH, SCRENHEIGHT, "HELLO !!");
    InitAudioDevice();
    Player player;
    Car car({-300, 335}, 250);
    Car car1({-375, 323}, 400);
    Car car2({-302, 138}, 200);
    Car car3({-324, 363}, 200);
    Car car4({-305, 283}, 140);
    Car car5({-295, 283}, 180);

    SetTargetFPS(60);

    Sound sound = LoadSound("assets/hitHurt.wav");


    while (!WindowShouldClose())    
    {
        player.RespawnPlayer();
       



        if(gameHasStarted) {
            
        bool isColliding = CheckCollisionRecs(player.GetKillRect(), car.GetKillRect()); 
        bool isColliding1 = CheckCollisionRecs(player.GetKillRect(), car1.GetKillRect()); 
        bool isColliding2 = CheckCollisionRecs(player.GetKillRect(), car2.GetKillRect()); 
        bool isColliding3 = CheckCollisionRecs(player.GetKillRect(), car3.GetKillRect()); 
        bool isColliding4 = CheckCollisionRecs(player.GetKillRect(), car4.GetKillRect()); 
        bool isColliding5 = CheckCollisionRecs(player.GetKillRect(), car5.GetKillRect()); 
       
        if(isColliding || isColliding1 || isColliding2 || isColliding3 || isColliding4 || isColliding5) {
            player.isAlive = false;        
            
        
        }
        
        if(IsKeyDown(KEY_B))    
            PlaySound(sound);
        
        
        player.StartingUI(); // MOVES THE FUNNY DEATH MESSAGE
        car.RecallCars();
        car1.RecallCars();
        car2.RecallCars();
        car1.RecallCars();
        car4.RecallCars();
        car5.RecallCars();


        ClearBackground(BLACK);
        
        player.GainPoints();
        player.OutOfBounds();
        player.Update();
        

        BeginDrawing(); // ________________________________BEGIN DRAWING _____________________________________________________
        
        car.Draw();
        car1.Draw();
        car2.Draw();
        car3.Draw();
        car4.Draw();
        car5.Draw();


        player.DrawScore();
        player.DrawHitbox(false); 
        player.Draw();
    // ---------------------------CARS----------------------------------
        

     
        if (player.score >= 1) {
            car.Update();
            car.DrawHitbox(isColliding);
        
        }

        if (player.score > 4) {
            car1.DrawHitbox(isColliding1);
            car1.Update();
          
        }
        if (player.score > 2) {
            car2.Update();
            car2.DrawHitbox(isColliding2);
        }
        if (player.score > 6) {
            car3.Update();
            car3.DrawHitbox(isColliding3);
            
        }

        if (player.score > 7) {
            car4.Update();
            car4.DrawHitbox(isColliding4);
            
        }

        if (player.score > 4) {
            car5.Update();
            car5.DrawHitbox(isColliding5);
            
        }


        }
        if (!player.isAlive)
            DrawText("to play again. Press enter", 250, 150, 25, BLUE);
        EndDrawing();
    }
    UnloadSound(sound);
    CloseAudioDevice();
    CloseWindow();
}