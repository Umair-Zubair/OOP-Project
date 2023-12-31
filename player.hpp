#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "health.hpp"
#include "vector"
#include "maze.hpp"
#include "enemy.hpp"


class Enemy;


class Player : public Entity{
    private:
        float speed;
        int player_hp;
        Health playerHealth;
        int currentFrameUpIndex = 0;
        int currentFrameDownIndex = 0;
        int currentFrameLeftIndex = 0;
        int currentFrameRightIndex = 0;
        int AttackUpFrame = 0;
        bool obstacleCollided = false;
        // std::vector<pixelRec> copyVector;
    public:
        // will hard code hp here in the constructor as it is a constant value that I decide(programmer).
        Player(float _x, float _y, SDL_Texture* _ptr);
        int getCurrentHealth() ;
        void decreaseHealth() ;
        void moveup(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Enemy& enemy);
        void movedown(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy);
        void moveleft(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy);
        void moveright(std::vector<Entity> wall,std::vector<Entity> checkObstacles, Entity& enemy);
        void updateUpAnimation(int currentFrameIndex);
        void updateLeftAnimation(int currentFrameIndex);
        void updateRightAnimation(int currentFrameIndex);
        void updateDownAnimation(int currentFrameIndex);
        void AttackUpAnimation(bool& animate, int startTime, Enemy& enemy);
        void AttackLeftAnimation(bool& animate, int startTime, Enemy& enemy);
        void AttackRightAnimation(bool& animate, int startTime, Enemy& enemy);
        void AttackDownAnimation(bool& animate, int startTime, Enemy& enemy);
        bool obstacleCollision();
        int getX(); // to get the x Coordinate of player for frame change.
        int getY(); // to get the y Coordinate of player for frame change.
        int setX(int _x); // need to set the location of the player according to frame change.
        int setY(int _y); // need to set the location of the player according to frame change.
        // void getVector();
};
