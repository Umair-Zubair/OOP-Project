#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity{
    private:
        float x, y;
        SDL_Rect currentLocation;
        SDL_Texture* ptr;
    public:
        Entity(float _x, float _y, SDL_Texture* ptr);
        void init();
        float getX();
        float GetY();
        SDL_Rect getCurrentLocation();
        SDL_Texture* getTexture();
};
