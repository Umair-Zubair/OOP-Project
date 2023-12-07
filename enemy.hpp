// #ifndef ENEMY_HPP
// #define ENEMY_HPP

// #include <iostream>
// #include <vector>
// #include <ctime>
// #include <cstdlib>
// #include "maze.hpp"
// #include "health.hpp"
// #include <SDL.h>
// #include "Entity.hpp"

// class Player;

// class Enemy {
// private:
//     std::pair<int, int> location;
//     std::string weaponType; // Using a string to represent the weapon type
//     maze* gameMaze; // Reference to the maze object
//     Health health;   // Health object
//     float speed;
//     int attackRange, enemy_hp;

// public:
//     // Constructor
//     Enemy(float _x, float _y, SDL_Texture* _ptr);

//     // Public member functions
//     std::pair<int, int> getLocation() const;
//     int getMaxHealth() const;
//     int getCurrentHealth() const;
//     std::string getWeaponType() const;
//     void decreaseHealth(int amount);
//     void moveTowardsPlayer(const Player& player, const maze& gameMaze);
//     void attackPlayer(Player& player);
// };

// #endif // ENEMY_HPP


// Enemy.hpp

#ifndef ENEMY_HPP
#define ENEMY_HPP

#include "Entity.hpp"
#include "maze.hpp"
#include "health.hpp"
#include <string>
using namespace std;

class Enemy : public Entity, public Health{
private:
    std::pair<int, int> location;
    string weaponType;
    maze* gameMaze;
    Health health;
    float speed;
    int attackRange, enemy_hp;

public:
    Enemy(float _x, float _y, SDL_Texture* _ptr);
    std::pair<int, int> getLocation() const;
    int getMaxHealth() const;
    int getCurrentHealth() const;
    string getWeaponType() const;
    void decreaseHealth(int amount);
    void moveAutomaticallyTowardsPlayer(const Entity& playerEntity, const maze& gameMaze);
    void attackPlayer(Entity& playerEntity);
};

#endif // ENEMY_HPP
