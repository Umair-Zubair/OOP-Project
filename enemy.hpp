#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "maze.hpp"
#include "health.hpp"

class Enemy {
private:
    std::pair<int, int> location;
    std::string weaponType; // Using a string to represent the weapon type
    maze* gameMaze; // Reference to the maze object
    Health health;   // Health object
    float speed;
    int attackRange, enemy_hp;

public:
    // Constructor
    Enemy(float _x, float _y, SDL_Texture* _ptr);

    // Public member functions
    std::pair<int, int> getLocation() const;
    int getMaxHealth() const;
    int getCurrentHealth() const;
    std::string getWeaponType() const;
    void decreaseHealth(int amount);
    void moveTowardsPlayer(const Player& player, const maze& gameMaze);
    void attackPlayer(Player& player);
};

#endif // ENEMY_HPP