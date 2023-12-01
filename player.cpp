//#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include "Entity.hpp"
#include "player.hpp"
#include <iostream>

void Player::getVector(){
    maze m1;
    copyVector = m1.getInvalid();
    
}

Player::Player(float _x, float _y, SDL_Texture* _ptr): Entity(_x, _y, _ptr), Health(100){
    speed = 8.0f;
    player_hp = 100;
}

void Player::moveup(std::vector<pixelRec> arr){
    y-=speed;
    if (y<=0){
        y=3;
    } 
    for (int i=0;i<arr.size();i++){
        //std::cout << arr[i].x_coord << " " << arr[i].y_coord << std::endl;
        if (arr[i].y_coord==getCurrentLocation().y){ 
            y = arr[i].y_coord;
            return;
        }
    } 

    //std::cout <<"Size of copy vector" << arr.size();
    
}

void Player::movedown(){
    for (int i=0;i<copyVector.size();i++){
        if (copyVector[i].y_coord=y){
            return;
        }
    }
    y+=speed;
    // need to make base condition.
    if (y>=620){
        y = 650;
    }
}

void Player :: moveright(){
    for (int i=0;i<copyVector.size();i++){
        if (copyVector[i].x_coord=x){
            return;
        }
    }
    x+= speed;
    // base condition.
    if (x>=1120){
        x = 1120;
    }
}

void Player :: moveleft(){
    for (int i=0;i<copyVector.size();i++){
        if (copyVector[i].x_coord=x){
            return;
        }
    }
    x-= speed;

    // base condition.
    if (x<10){
        x = 10;
    }
}

