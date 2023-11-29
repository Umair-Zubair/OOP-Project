#include "Entity.hpp"
#include <SDL.h>
#include <SDL_image.h>

Entity::Entity(float _x, float _y, SDL_Texture *_ptr): x(_x), y(_y), ptr(_ptr){
    // this is for src_rect;
    currentLocation.x = 0;
    currentLocation.y = 0;
    currentLocation.w = 200;
    currentLocation.h = 400;
}
float Entity::getX(){
    return x;
}

float Entity::GetY(){
    return y;
}

SDL_Texture* Entity::getTexture(){
    return ptr;
}

SDL_Rect Entity::getCurrentLocation(){
    return currentLocation;
}
