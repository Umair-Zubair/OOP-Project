#pragma once
#include <SDL.h>
#include<SDL_Image.h>
#include "Entity.hpp"

class showHealth: public Entity{
    private:

    public:
        showHealth(float _x, float _y, SDL_Texture* _ptr);
        void changeHealth(int health);
};