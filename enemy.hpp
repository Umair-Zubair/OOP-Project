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
#include "player.hpp"
#include "showHealth.hpp"
using namespace std;


class Player;

class Enemy : public Entity{
    private:
        string weaponType, currentDirection;
        Health enemyHealth;
        float speed;
        int attackRange, enemy_hp, frameWidth, frameHeight, animationSpeed, animationStartTime;
        int currentFrameUpIndex = 0;
        int currentFrameDownIndex = 0;
        int currentFrameLeftIndex = 0;
        int currentFrameRightIndex = 0;
        int lastAnimationTime;
        int animationDelay;
        
    public:
        Enemy(float _x, float _y, SDL_Texture* _ptr);
        int getMaxHealth() const;
        int getCurrentHealth();
        void decreaseHealth();
        string getWeaponType() const;
        void moveTowardsPlayer(Player& player, showHealth& playerHealth, std::vector<Entity>& wall, std::vector<Entity>& checkObstacles);
        void attackPlayer(Entity& playerEntity);
        void updateUpAnimation(int currentFrameIndex);
        void updateDownAnimation(int currentFrameIndex);
        void updateLeftAnimation(int currentFrameIndex);
        void updateRightAnimation(int currentFrameIndex);
        void AttackUpAnimation(Player& player);
        void AttackDownAnimation(Player& player);
        void AttackLeftAnimation(Player& player);
        void AttackRightAnimation(Player& player);
};

#endif // ENEMY_HPP