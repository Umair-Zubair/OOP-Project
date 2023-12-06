//#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include "Entity.hpp"
#include "player.hpp"
#include <iostream>

// void Player::getVector(){
//     maze m1;
//     copyVector = m1.getInvalid();
    
// }

Player::Player(float _x, float _y, SDL_Texture* _ptr): Entity(_x, _y, _ptr), Health(100){
    change_src(155, 52, 74, 76);
    speed = 8.0f;
    player_hp = 100;
}

void Player::moveup(std::vector<Entity> wall){
    y-=speed;
    change_src(155, 52, 74, 76);
    if (y<=0){
        y=3;
    } 
    for (int i=0;i<wall.size();i++){
        if (y < (wall[i].GetY() + 75) && (y + 75) > wall[i].GetY() &&
            x < (wall[i].getX() + 75) && (x + 75) > wall[i].getX()) {
            y = wall[i].GetY() + 77;
        }
    } 
}

void Player::movedown(std::vector<Entity> wall){
    y += speed;
    change_src(33, 41, 76, 87);
    for (int i = 0; i < wall.size(); i++){
        if (y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75 &&
            x + 75 > wall[i].getX() && x < wall[i].getX() + 75) {
            y = wall[i].GetY() - 77;
        }
    } 
    if (y >= 620){
        y = 620;
    }
}

void Player::moveright(std::vector<Entity> wall){
    x += speed;
    change_src(431, 63, 60, 65);
    for (int i = 0; i < wall.size(); i++){
        if (x + 75 > wall[i].getX() && x < wall[i].getX() + 75 &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].getX() - 75;
        }
    } 
    if (x >= 1120){
        x = 1120;
    }
}

void Player::moveleft(std::vector<Entity> wall){
    x -= speed;
    change_src(292, 58, 62, 70);
    for (int i = 0; i < wall.size(); i++){
        if (x < wall[i].getX() + 75 && x + 75 > wall[i].getX() &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].getX() + 75;
        }
    } 
    if (x < 10){
        x = 1;
    }
}


