#include "enemy.hpp"

Enemy::Enemy(int mazeSize, maze* mazeObj) : gameMaze(mazeObj) {
    srand(static_cast<unsigned>(time(nullptr)));
    location = std::make_pair(rand() % mazeSize, rand() % mazeSize);
    health = 100;
    weapons = {"Gun"};
}

std::pair<int, int> Enemy::getLocation() const {
    return location;
}

int Enemy::getHealth() const {
    return health;
}

std::vector<std::string> Enemy::getWeapons() const {
    return weapons;
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
    // Select a random weapon from the available weapons
    int randomIndex = rand() % weapons.size();
    std::string selectedWeapon = weapons[randomIndex];

    // Calculate the damage based on the selected weapon
    int damage;
    if (selectedWeapon == "Sword") {
        damage = rand() % 11 + 10; // Random damage between 10 and 20
    } else if (selectedWeapon == "Bow") {
        damage = rand() % 11 + 5;  // Random damage between 5 and 15
    } else if (selectedWeapon == "Dagger") {
        damage = rand() % 11 + 8;  // Random damage between 8 and 18
    }

    return damage;
}
