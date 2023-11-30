#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include "Entity.hpp"
#include "player.hpp"

Player::Player(float _x, float _y, SDL_Texture* _ptr): Entity(_x, _y, _ptr), Health(100){
    speed = 8.0f;
    player_hp = 100;
}

void Player::moveup(){
    y-= speed;
    // need to make condition for staying in screen;
    if (y<=0){
        y=3;
    }
}

void Player::movedown(){
    y+=speed;
    // need to make base condition.
    if (y>=620){
        y = 650;
    }
}

void Player :: moveright(){
    x+= speed;

    // base condition.
    if (x>=1120){
        x = 1120;
    }
}

void Player :: moveleft(){
    x-= speed;

    // base condition.
    if (x<10){
        x = 10;
    }
}

