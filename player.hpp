//#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "health.hpp"
#include "vector"
#include "maze.hpp"
#ifndef PLAYER_HPP
#define PLAYER_HPP

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
        // std::vector<pixelRec> copyVector;
    public:
        // will hard code hp here in the constructor as it is a constant value that I decide(programmer).
        Player(float _x, float _y, SDL_Texture* _ptr);
        int getCurrentHealth() ;
        void decreasePlayerHealth() ;
        void moveup(std::vector<Entity> wall);
        void movedown(std::vector<Entity> wall);
        void moveleft(std::vector<Entity> wall);
        void moveright(std::vector<Entity> wall);
        void updateUpAnimation(int currentFrameIndex);
        void updateLeftAnimation(int currentFrameIndex);
        void updateRightAnimation(int currentFrameIndex);
        void updateDownAnimation(int currentFrameIndex);
        void AttackUp();
        void AttackUpAnimation(bool& animate, int startTime);
        void AttackLeftAnimation(bool& animate, int startTime);
        void AttackRightAnimation(bool& animate, int startTime);
        void AttackDownAnimation(bool& animate, int startTime);
        // void getVector();
};

#endif 