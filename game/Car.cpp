#include "Car.hpp"


Car::Car() {


};

Car::~Car() {
    UnloadTexture(sprite);
};

void Car::Draw() {
    DrawTextureV(sprite, carPos, WHITE);
}

void Car::Update() {
    
}