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

Player::Player(float _x, float _y, SDL_Texture* _ptr): Entity(_x, _y, _ptr), Health(){
    change_src(13,7,22,32);
    speed = 8.0f;
    player_hp = 100;
}

void Player::moveup(std::vector<Entity> wall){
    y-=speed;
    updateUpAnimation(currentFrameUpIndex);
    currentFrameUpIndex = (currentFrameUpIndex + 1) % 8;
    if (y<=0){
        y=3;
    } 
    for (int i=0;i<wall.size();i++){
        if (y < (wall[i].GetY() + 75) && (y + 75) > wall[i].GetY() &&
            x < (wall[i].GetX() + 75) && (x + 75) > wall[i].GetX()) {
            y = wall[i].GetY() + 77;
        }
    } 
}

void Player::movedown(std::vector<Entity> wall){
    y += speed;
    updateDownAnimation(currentFrameDownIndex);
    currentFrameDownIndex = (currentFrameDownIndex + 1) % 8;
    for (int i = 0; i < wall.size(); i++){
        if (y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75 &&
            x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75) {
            y = wall[i].GetY() - 77;
        }
    } 
    if (y >= 620){
        y = 620;
    }
}

void Player::moveright(std::vector<Entity> wall){
    x += speed;
    updateRightAnimation(currentFrameRightIndex);
    currentFrameRightIndex = (currentFrameRightIndex + 1) % 8;
    for (int i = 0; i < wall.size(); i++){
        if (x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75 &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].GetX() - 75;
        }
    } 
    if (x >= 1120){
        x = 1120;
    }
}

void Player::moveleft(std::vector<Entity> wall){
    x -= speed;
    updateLeftAnimation(currentFrameLeftIndex);
    currentFrameLeftIndex = (currentFrameLeftIndex + 1) % 8;
    for (int i = 0; i < wall.size(); i++){
        if (x < wall[i].GetX() + 75 && x + 75 > wall[i].GetX() &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].GetX() + 75;
        }
    } 
    if (x < 10){
        x = 1;
    }
}

void Player::updateUpAnimation(int currentFrameIndex) {
    // Update animation frame
    if (currentFrameIndex == 0) {
        change_src(13,7,22,32);
    } else if (currentFrameIndex == 1) {
        change_src(60,7,22,32);
    } else if(currentFrameIndex == 2){
        change_src(108,6,22,32);
    } else if (currentFrameIndex == 3) {
        change_src(156,6,22,32);
    } else if (currentFrameIndex == 4) {
        change_src(205,6,22,32);
    } else if (currentFrameIndex == 5) {
        change_src(255,7,22,30);
    } else if (currentFrameIndex == 6) {
        change_src(303,6,22,30);
    } else {
        change_src(351,6,22,30);
    }

}

void Player::updateLeftAnimation(int currentFrameIndex) {
    // Update animation frame
    if (currentFrameIndex == 0) {
        change_src(15,58,20,31);
    } else if (currentFrameIndex == 1) {
        change_src(64,58,18,28);
    } else if(currentFrameIndex == 2){
        change_src(113,57,16,29);
    } else if (currentFrameIndex == 3) {
        change_src(161,57,16,29);
    } else if (currentFrameIndex == 4) {
        change_src(207,58,20,31);
    } else if (currentFrameIndex == 5) {
        change_src(254,58,18,30);
    } else if (currentFrameIndex == 6) {
        change_src(302,57,19,31);
    } else {
        change_src(350,57,19,31);
    }

}


void Player::updateRightAnimation(int currentFrameIndex) {
    // Update animation frame based on the direction
    if (currentFrameIndex == 0) {
        change_src(12, 106, 20, 31);
    } else if (currentFrameIndex == 1) {
        change_src(60,106,19,28);
    } else if(currentFrameIndex == 2) {
        change_src(109,105,18,29);
    } else if (currentFrameIndex == 3) {
        change_src(157,105,18,29);
    } else if (currentFrameIndex == 4) {
        change_src(204,106,20,31);
    } else if (currentFrameIndex == 5) {
        change_src(251,106,21,30);
    } else if (currentFrameIndex == 6) {
        change_src(299,105,22,31);
    } else {
        change_src(347,105,22,31);
    }
}

void Player::updateDownAnimation(int currentFrameIndex) {
    // Update animation frame
    if (currentFrameIndex == 0) {
        change_src(12, 151, 22, 32);
    } else if (currentFrameIndex == 1) {
        change_src(61,151,22,30);
    } else if(currentFrameIndex == 2) {
        change_src(109,150,22,30);
    } else if (currentFrameIndex == 3) {
        change_src(157,150,22,30);
    } else if (currentFrameIndex == 4) {
        change_src(204,151,22,32);
    } else if (currentFrameIndex == 5) {
        change_src(251,151,22,30);
    } else if (currentFrameIndex == 6) {
        change_src(299,150,22,30);
    } else {
        change_src(347,150,22,31);
    }
}


