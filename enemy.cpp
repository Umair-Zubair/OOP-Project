#include "enemy.hpp"

Enemy::Enemy(int mazeSize, maze* mazeObj) : gameMaze(mazeObj), health(100) {
    srand(static_cast<unsigned>(time(nullptr)));
    location = std::make_pair(rand() % mazeSize, rand() % mazeSize);
    weaponType = "Sword"; // Only one weapon type, i.e., Sword
}

// hello

std::pair<int, int> Enemy::getLocation() const {
    return location;
}

int Enemy::getMaxHealth() const {
    return health.getMaxHealth();
}

int Enemy::getCurrentHealth() const {
    return health.getCurrentHealth();
}

std::string Enemy::getWeaponType() const {
    return weaponType;
}

void Enemy::moveTowardsPlayer(const std::pair<int, int>& playerLocation) {
    int playerX = playerLocation.first;
    int playerY = playerLocation.second;
    int enemyX = location.first;
    int enemyY = location.second;

    // Move one step closer to the player in either x or y direction
    if (enemyX < playerX && gameMaze->isValidMove(enemyX + 1, enemyY)) {
        location.first = enemyX + 1;
    } else if (enemyX > playerX && gameMaze->isValidMove(enemyX - 1, enemyY)) {
        location.first = enemyX - 1;
    } else if (enemyY < playerY && gameMaze->isValidMove(enemyX, enemyY + 1)) {
        location.second = enemyY + 1;
    } else if (enemyY > playerY && gameMaze->isValidMove(enemyX, enemyY - 1)) {
        location.second = enemyY - 1;
    }
}

int Enemy::attackPlayer() {
    // Damage based on the weapon type
    int damage = 0;
    if (weaponType == "Sword") {
        damage = 15; // Constant damage for the sword
    }
    // Add conditions for other weapon types if needed in the future

    return damage;
}

void Enemy::decreaseHealth(int amount) {
    health.decreaseHealth(amount);
}