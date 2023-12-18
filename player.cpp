//#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include "Entity.hpp"
#include "Player.hpp"
#include <iostream>
using namespace std;

// void Player::getVector(){
//     maze m1;
//     copyVector = m1.getInvalid();
    
// }

Player::Player(float _x, float _y, SDL_Texture* _ptr): Entity(_x, _y, _ptr){
    change_src(13,7,22,32);
    speed = 8.0f;
    player_hp = 100;
}

int Player::getCurrentHealth() {
    // cout << playerHealth.getCurrentHealth();
    return playerHealth.getCurrentHealth();
}

void Player::decreaseHealth() {
    playerHealth.decreasePlayerHealth();
}

void Player::moveup(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Enemy& enemy){
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
    for (int i=0;i<checkObstacles.size();i++){
        if (checkCollision(checkObstacles[i])) {
            std::cout << "Wah yaar" << endl;
            // obstacleCollided = true;
        }
    } 
    // std::cout << checkCollision(enemy);
    if (checkCollision(enemy)) {

        y = enemy.GetY() + enemy.getCurrentLocation().h + 30.0f;
    }
}

void Player::movedown(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy) {
    y += speed;
    updateDownAnimation(currentFrameDownIndex);
    currentFrameDownIndex = (currentFrameDownIndex + 1) % 8;

    // Check collision with walls
    for (int i = 0; i < wall.size(); i++) {
        if (y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75 &&
            x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75) {
            y = wall[i].GetY() - 77;
        }
    }
    for (int i = 0; i < checkObstacles.size(); i++) {
        if (checkCollision(checkObstacles[i])) {
            std::cout << "Wah yaar" << endl;
            // obstacleCollided = true;
        }
    }

    // Check collision with enemy
    if (checkCollision(enemy)) {
        y = enemy.GetY() - getCurrentLocation().h - 30.0f;
    }

    if (y >= 620) {
        y = 620;
    }
}

void Player::moveright(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy) {
    x += speed;
    updateRightAnimation(currentFrameRightIndex);
    currentFrameRightIndex = (currentFrameRightIndex + 1) % 8;

    // Check collision with walls
    for (int i = 0; i < wall.size(); i++) {
        if (x + 75 > wall[i].GetX() && x < wall[i].GetX() + 75 &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].GetX() - 75;
        }
    }
    for (int i = 0; i < checkObstacles.size(); i++) {
        if (checkCollision(checkObstacles[i])) {
            std::cout << "Wah yaar" << endl;
            // obstacleCollided = true;
        }
    }
    // Check collision with enemy
    if (checkCollision(enemy)) {
        x = enemy.GetX() - getCurrentLocation().w - 30.0f;
    }
    
    if (x >= 1120) {
        x = 1120;
    }
}

void Player::moveleft(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy) {
    x -= speed;
    updateLeftAnimation(currentFrameLeftIndex);
    currentFrameLeftIndex = (currentFrameLeftIndex + 1) % 8;

    // Check collision with walls
    for (int i = 0; i < wall.size(); i++) {
        if (x < wall[i].GetX() + 75 && x + 75 > wall[i].GetX() &&
            y + 75 > wall[i].GetY() && y < wall[i].GetY() + 75) {
            x = wall[i].GetX() + 75;
        }
    }
    for (int i = 0; i < checkObstacles.size(); i++) {
        if (checkCollision(checkObstacles[i])) {
            std::cout << "Wah yaar" << endl;
            // obstacleCollided = true;
        }
    }
    // Check collision with enemy
    if (checkCollision(enemy)) {
        x = enemy.GetX() + enemy.getCurrentLocation().w + 30.0f;
    }

    if (x < 10) {
        x = 1;
    }
}

bool Player::obstacleCollision(){
    return obstacleCollided;
}

// All WALKING ANIMATIONS.

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
// ALL ATTACK ANIMATIONS NOW.

void Player::AttackUpAnimation(bool& animate, int startTime, Enemy& enemy) {
    static int currentFrameIndex = 0;
    if (animate)
    {
        // std::cout<<currentFrameIndex<<"\n";
        switch(currentFrameIndex)
        {
            case 0:
                if (startTime + 116 <= SDL_GetTicks())
                {
                    change_src(13,204,22,29);
                    currentFrameIndex++;
  
                }
                break;
            case 1:
                if (startTime + 232 <= SDL_GetTicks())
                {
                    change_src(61,205,22,29);
                    currentFrameIndex++;
                }
                break;
            case 2:
                if (startTime + 348 <= SDL_GetTicks())
                {
                    change_src(104,192,39,44);
                    currentFrameIndex++;
                }
                break;
            case 3:
                if (startTime + 464 <= SDL_GetTicks())
                {
                    change_src(152,194,23,34);
                    currentFrameIndex++;

                }
                break;
            case 4:
                if (startTime + 580 <= SDL_GetTicks())
                {
                    change_src(200,194,23,34);
                    currentFrameIndex++;

                }
                break;
            case 5:
                if (startTime + 700 <= SDL_GetTicks())
                {
                    change_src(253,204,22,29);
                    currentFrameIndex = 0;
                    animate = false;
                    // std::cout << "animated\n";
                    if (AttackCollision(enemy)) {
                        enemy.decreaseHealth();
                        // std::cout <<enemy.getCurrentHealth();
                    }

                }
                break;
        }
    }
}


void Player::AttackLeftAnimation(bool& animate, int startTime, Enemy& enemy) {
    static int currentFrameIndex = 0;
    if (animate)
    {
        // std::cout<<currentFrameIndex<<"\n";
        switch(currentFrameIndex)
        {
            case 0:  
                if (startTime + 116 <= SDL_GetTicks())
                {
                    change_src(15,252,20,31);
                    currentFrameIndex++;
                }
                break;

            case 1:
                if (startTime + 232 <= SDL_GetTicks())
                {
                    change_src(63,253,20,30);
                    currentFrameIndex++;
                }
                break;

            case 2:
                if (startTime + 348 <= SDL_GetTicks())
                {
                    change_src(96,248,44,40);
                    currentFrameIndex++;
                }
                break;
            case 3:
                if (startTime + 464 <= SDL_GetTicks())
                {
                    change_src(145,254,31,34);
                    currentFrameIndex++;
                }
                break;
            case 4:
                
                if (startTime + 580 <= SDL_GetTicks())
                {
                    change_src(193,254,31,34);
                    currentFrameIndex++;
                }
                break;
            case 5:
                
                if (startTime + 700 <= SDL_GetTicks())
                {
                    change_src(255,252,20,31);
                    currentFrameIndex = 0;
                    animate = false;
                    if (AttackCollision(enemy)) {
                        enemy.decreaseHealth();
                        // std::cout <<enemy.getCurrentHealth();
                    }
                }
                break;
            
        }
    }
}

void Player::AttackRightAnimation(bool& animate, int startTime, Enemy& enemy) {
    // Update animation frame
    static int currentFrameIndex = 0;
    if (animate)
    {
        // std::cout<<currentFrameIndex<<"\n";
        switch(currentFrameIndex)
        {
            case 0:  
                if (startTime + 116 <= SDL_GetTicks())
                {
                    change_src(12,299,20,31);
                    currentFrameIndex++;
                }
                break;

            case 1:
                if (startTime + 232 <= SDL_GetTicks())
                {
                    change_src(60,298,20,32);
                    currentFrameIndex++;
                }
                break;

            case 2:
                if (startTime + 348 <= SDL_GetTicks())
                {
                    change_src(100,295,44,40);
                    currentFrameIndex++;
                }
                break;
            case 3:
                if (startTime + 464 <= SDL_GetTicks())
                {
                    change_src(161,295,30,36);
                    currentFrameIndex++;
                }
                break;
            case 4:
                
                if (startTime + 580 <= SDL_GetTicks())
                {
                    change_src(209,295,30,36);
                    currentFrameIndex++;
                }
                break;
            case 5:
                
                if (startTime + 700 <= SDL_GetTicks())
                {
                    change_src(252,299,20,31);
                    currentFrameIndex = 0;
                    animate = false;
                    if (AttackCollision(enemy)) {
                        // std::cout << "Player hit the enemy!" << std::endl;
                        enemy.decreaseHealth();
                        // std::cout <<enemy.getCurrentHealth();
                    }
                }
                break;
            
        }
    }
}

void Player::AttackDownAnimation(bool& animate, int startTime, Enemy& enemy) {
    // Update animation frame
    static int currentFrameIndex = 0;
    if (animate)
    {
        // std::cout<<currentFrameIndex<<"\n";
        switch(currentFrameIndex)
        {
            case 0:  
                if (startTime + 116 <= SDL_GetTicks())
                {
                    change_src(15, 341, 20, 30);
                    currentFrameIndex++;
                }
                break;

            case 1:
                if (startTime + 232 <= SDL_GetTicks())
                {
                    change_src(63,340,20,31);
                    currentFrameIndex++;
                }
                break;

            case 2:
                if (startTime + 348 <= SDL_GetTicks())
                {
                    change_src(97,340,39,44);
                    currentFrameIndex++;
                }
                break;
            case 3:
                if (startTime + 464 <= SDL_GetTicks())
                {
                    change_src(161,348,21,34);
                    currentFrameIndex++;
                }
                break;
            case 4:
                
                if (startTime + 580 <= SDL_GetTicks())
                {
                    change_src(209,348,21,34);
                    currentFrameIndex++;
                }
                break;
            case 5:
                
                if (startTime + 700 <= SDL_GetTicks())
                {
                    change_src(255,341,20,30);
                    currentFrameIndex = 0;
                    animate = false;
                    if (AttackCollision(enemy)) {
                        enemy.decreaseHealth();
                        // std::cout <<enemy.getCurrentHealth();
                    }
                }
                break;
        }
    }
}

// void Player::attack(std::vector<Enemy>& enemies) {
//     // Check for collision with enemies during attack
    
//     for (auto& enemy : enemies) {
//         if (checkCollision(enemy)) {
//             std::cout << "Player hit the enemy!" << std::endl;
//             // enemy.decreaseHealth();
//         }
//     }
// }
