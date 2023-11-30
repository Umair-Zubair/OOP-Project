#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "health.hpp"


class Player: public Entity, public Health{
    private:
        float speed;
        int player_hp;

    public:
        // will hard code hp here in the constructor as it is a constant value that I decide(programmer).
        Player(float _x, float _y, SDL_Texture* _ptr);
        void moveup();
        void movedown();
        void moveleft();
        void moveright();


};