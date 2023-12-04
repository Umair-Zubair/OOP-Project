#include "enemy.hpp"

Enemy::Enemy(float _x, float _y, SDL_Texture* _ptr) : Entity(_x, _y, _ptr), speed(3.0f), attackRange(50), enemy_hp(100){
    
}

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

void Enemy::moveTowardsPlayer(const Player& player, const maze& gameMaze) {
    // Calculate the direction vector from the enemy to the player
    float dx = player.getX() - x;
    float dy = player.getY() - y;
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

void Enemy::attackPlayer(Player& player) {
    // Calculate the distance to the player
    float dx = player.getX() - x;
    float dy = player.getY() - y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // Check if the player is within the attack range
    if (distance < attackRange) {
        // Implement your attack logic here
        // For example, decrease player health
        player.decreaseHealth(10); // Adjust the damage value based on your needs
        std::cout << "Enemy attacks player!" << std::endl;
    }
}
