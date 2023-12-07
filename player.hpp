//#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "health.hpp"
#include "vector"
#include "maze.hpp"

class Player : public Entity, public Health{
    private:
        float speed;
        int player_hp;
        // std::vector<pixelRec> copyVector;
    public:
        // will hard code hp here in the constructor as it is a constant value that I decide(programmer).
        Player(float _x, float _y, SDL_Texture* _ptr);
        void moveup(std::vector<Entity> wall);
        void movedown(std::vector<Entity> wall);
        void moveleft(std::vector<Entity> wall);
        void moveright(std::vector<Entity> wall);
        // void getVector();

};