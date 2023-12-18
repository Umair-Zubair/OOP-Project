#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Enemy;

class Entity{
    protected:
        float x, y;
        SDL_Rect currentLocation;
        SDL_Texture* ptr;
        SDL_Rect dstRect;
    public:
        Entity(float _x, float _y, SDL_Texture* ptr);
        float GetX() const;
        float GetY() const;
        float GetWidth() const;
        float GetHeight() const;
        SDL_Rect getCurrentLocation() const;
        SDL_Texture* getTexture();
        void change_src(float x, float y, float width, float height);
        bool checkCollision(const Entity& other); //Enemy and player colision.
        bool AttackCollision(const Entity& enemy);
        virtual ~Entity(){}
};


