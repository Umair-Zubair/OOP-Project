#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Entity{
    protected:
        float x, y;
        SDL_Rect currentLocation;
        SDL_Texture* ptr;
    public:
        Entity(float _x, float _y, SDL_Texture* ptr);
        void init();
        float GetX() const;
        float GetY() const;
        SDL_Rect getCurrentLocation();
        SDL_Texture* getTexture();
        void change_src(float x, float y, float width, float height);
        virtual ~Entity(){}
};


