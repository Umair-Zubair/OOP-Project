// Enemy.cpp

#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include "health.hpp"
#include "Entity.hpp"

Enemy::Enemy(float _x, float _y, SDL_Texture* _ptr) : Entity(_x, _y, _ptr), speed(1.0f), attackRange(10), enemy_hp(100){
    change_src(431, 63, 60, 65);
}

int Enemy::getCurrentHealth() {
    return enemyHealth.getCurrentHealth();
}

void Enemy::decreaseEnemyHealth() {
    enemyHealth.decreaseHealth();
}

std::string Enemy::getWeaponType() const {
    return weaponType;
}

void Enemy::moveTowardsPlayer(Player& player, maze& gameMaze) {
    // Calculate the direction vector from the enemy to the player
    float dx = player.GetX() - x;
    float dy = player.GetY() - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Normalize the direction vector
    if (distance != 0) {
        dx /= distance;
        dy /= distance;
    }

    // Calculate the next position based on the direction vector and speed
    float nextX = x + dx * speed;
    float nextY = y + dy * speed;

    // Check if the next position is a valid move in the maze
    if (gameMaze.isValidMove(nextX, nextY)) {
        x = nextX;
        y = nextY;
    }

    if (distance < attackRange) {
        if (player.getCurrentHealth() > 0){
            player.decreasePlayerHealth();
        }
    }
}