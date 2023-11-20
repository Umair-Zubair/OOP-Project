#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "maze.hpp"

class Enemy {
private:
    std::pair<int, int> location;
    int health;
    std::vector<std::string> weapons;
    maze* gameMaze; // Reference to the maze object

public:
    // Constructor
    Enemy(int mazeSize, maze* mazeObj);

    // Public member functions
    std::pair<int, int> getLocation() const;
    int getHealth() const;
    std::vector<std::string> getWeapons() const;
    void moveTowardsPlayer(const std::pair<int, int>& playerLocation);
    int attackPlayer();
};

#endif // ENEMY_HPP
