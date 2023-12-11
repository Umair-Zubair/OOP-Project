// Enemy.cpp

#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include "health.hpp"
#include "Entity.hpp"

Enemy::Enemy(float _x, float _y, SDL_Texture* _ptr) : Entity(_x, _y, _ptr), speed(1.0f), attackRange(10), enemy_hp(100), lastAnimationTime(SDL_GetTicks()){
    change_src(16, 12, 24, 29);
    animationDelay = 100;
    currentDirection = "Up";
}

int Enemy::getCurrentHealth() {
    return enemyHealth.getCurrentHealth();
}

void Enemy::decreaseHealth() {
    enemyHealth.decreaseEnemyHealth();
}

std::string Enemy::getWeaponType() const {
    return weaponType;
}

void Enemy::moveTowardsPlayer(Player& player, maze& gameMaze) {
    float dx = player.GetX() - x;
    float dy = player.GetY() - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    if (distance != 0) {
        dx /= distance;
        dy /= distance;
    }

    if (std::abs(dx) > std::abs(dy)) {
        currentDirection = (dx > 0) ? "Right" : "Left";
    } else {
        if (!checkCollision(player)) {
            currentDirection = (dy > 0) ? "Down" : "Up";
        }
    }

    float nextX = x + dx * speed;
    float nextY = y + dy * speed;

    if (gameMaze.isValidMove(nextX, nextY)) {
        if (!checkCollision(player)) {
            x = nextX;
        }
        if (!checkCollision(player)) {
            y = nextY;
        }
    }

    // Check if enough time has passed for the next animation frame
    int currentTime = SDL_GetTicks();
    int deltaTime = currentTime - lastAnimationTime;

    if (deltaTime >= animationDelay) {
        // Update animations based on the current direction
        if (currentDirection == "Up") {
            updateUpAnimation(currentFrameUpIndex);
            currentFrameUpIndex = (currentFrameUpIndex + 1) % 6;
        } else if (currentDirection == "Down") {
            updateDownAnimation(currentFrameDownIndex);
            currentFrameDownIndex = (currentFrameDownIndex + 1) % 6;
        } else if (currentDirection == "Left") {
            updateLeftAnimation(currentFrameLeftIndex);
            currentFrameLeftIndex = (currentFrameLeftIndex + 1) % 6;
        } else if (currentDirection == "Right") {
            updateRightAnimation(currentFrameRightIndex);
            currentFrameRightIndex = (currentFrameRightIndex + 1) % 6;
        }

        // Update the animation timer
        lastAnimationTime = currentTime;
    }

    if (distance < attackRange) {
        if (player.getCurrentHealth() > 0) {
            player.decreasePlayerHealth();
        }
    }
}

void Enemy::updateUpAnimation(int currentFrameIndex) {

    if (currentFrameIndex == 0) {
        change_src(16,204,24,29);
    } else if (currentFrameIndex == 1) {
        change_src(64,204,23,28);
    } else if(currentFrameIndex == 2){
        change_src(112,203,22,28);
    } else if (currentFrameIndex == 3) {
        change_src(160,204,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(209,204,23,28);
    } else if (currentFrameIndex == 5) {
        change_src(257,203,23,28);
    }
}

void Enemy:: updateDownAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(8, 252, 24, 29);
    } else if (currentFrameIndex == 1) {
        change_src(56,252,24,28);
    } else if(currentFrameIndex == 2){
        change_src(105,251,23,28);
    } else if (currentFrameIndex == 3) {
        change_src(125,252,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(199,252,24,28);
    } else if (currentFrameIndex == 5) {
        change_src(247,251,24,28);
    }

}

void Enemy:: updateLeftAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(9, 348, 24, 29);
    } else if (currentFrameIndex == 1) {
        change_src(55,348,27,28);
    } else if(currentFrameIndex == 2){
        change_src(103,347,28,26);
    } else if (currentFrameIndex == 3) {
        change_src(153,348,24,29);
    } else if (currentFrameIndex == 4) {
        change_src(203,348,21,28);
    } else if (currentFrameIndex == 5) {
        change_src(251,347,21,26);
    }
}

void Enemy:: updateRightAnimation(int currentFrameIndex){

    if (currentFrameIndex == 0) {
        change_src(16, 300, 17, 29);
    } else if (currentFrameIndex == 1) {
        change_src(63,300,20,28);
    } else if(currentFrameIndex == 2){
        change_src(110,299,21,26);
    } else if (currentFrameIndex == 3) {
        change_src(160,300,17,29);
    } else if (currentFrameIndex == 4) {
        change_src(209,300,15,28);
    } else if (currentFrameIndex == 5) {
        change_src(257,299,17,26);
    }
}