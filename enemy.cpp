// Enemy.cpp

#include "Enemy.hpp"
#include <cmath>
#include <iostream>
#include "Player.hpp"
#include "health.hpp"
#include "Entity.hpp"

Enemy::Enemy(float _x, float _y, SDL_Texture* _ptr) : Entity(_x, _y, _ptr), speed(3.0f), attackRange(50), enemy_hp(100) , Health(){
    change_src(431, 63, 60, 65);
}

int Enemy::getCurrentHealth() const {
    return health.getCurrentHealth();
}

std::string Enemy::getWeaponType() const {
    return weaponType;
}

void Enemy::moveAutomaticallyTowardsPlayer(const Entity& playerEntity, const maze& gameMaze) {
    // Calculate the direction vector from the enemy to the player
    float dx = playerEntity.GetX() - x;
    float dy = playerEntity.GetY() - y;
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
    if (gameMaze.isValidMove(static_cast<int>(nextX), static_cast<int>(nextY))) {
        x = nextX;
        y = nextY;
    }
}

void Enemy::decreaseHealth(int amount) {
    health.decreaseHealth(amount);
}

void Enemy::attackPlayer(Entity& playerEntity) {
    // Calculate the distance to the player
    float dx = playerEntity.GetX() - x;
    float dy = playerEntity.GetY() - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Check if the player is within the attack range
    if (distance < attackRange) {
        // Implement your attack logic here
        // For example, decrease player health
        health.decreaseHealth(10); // Adjust the damage value based on your needs
        std::cout << "Enemy attacks player!" << std::endl;
    }
}