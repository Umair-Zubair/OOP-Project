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

public:
    // Constructor
    Enemy(int mazeSize, maze* mazeObj);

    // Public member functions
    std::pair<int, int> getLocation() const;
    int getMaxHealth() const;
    int getCurrentHealth() const;
    std::string getWeaponType() const;
    void moveTowardsPlayer(const std::pair<int, int>& playerLocation);
    int attackPlayer();
    void decreaseHealth(int amount);
};

#endif // ENEMY_HPP