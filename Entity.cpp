// #include "Entity.hpp"
// #include <SDL.h>
// #include <SDL_image.h>

// Entity::Entity(float _x, float _y, SDL_Texture *_ptr): x(_x), y(_y), ptr(_ptr){
//     // this is for src_rect;
//     currentLocation.x = 0;
//     currentLocation.y = 0;
//     currentLocation.w = 200;
//     currentLocation.h = 400;
// }
// float Entity::getX(){
//     return x;
// }

// void Entity::change_src(float _x, float _y, float width, float height){
//     currentLocation.x = _x;
//     currentLocation.y = _y;
//     currentLocation.w = width;
//     currentLocation.h = height;
// }

// float Entity::GetY(){
//     return y;
// }

// SDL_Texture* Entity::getTexture(){
//     return ptr;
// }

// SDL_Rect Entity::getCurrentLocation(){
//     return currentLocation;
// }

#include "Entity.hpp"

Entity::Entity(float _x, float _y, SDL_Texture* _ptr) : x(_x), y(_y), ptr(_ptr) {
    // this is for src_rect;
    currentLocation.x = 0;
    currentLocation.y = 0;
    currentLocation.w = 200;
    currentLocation.h = 400;
}

float Entity::GetX() const{
    return x;
}

float Entity::GetY() const{
    return y;
}

SDL_Rect Entity::getCurrentLocation() {
    return currentLocation;
}

SDL_Texture* Entity::getTexture() {
    return ptr;
}

void Entity::change_src(float _x, float _y, float width, float height) {
    currentLocation.x = _x;
    currentLocation.y = _y;
    currentLocation.w = width;
    currentLocation.h = height;
}

bool Entity::checkCollision(const Entity& other) const {
    // Check for collision based on bounding boxes
    const float epsilon = 10.0f;
    return (GetX() < other.GetX() + other.currentLocation.w &&
            GetX() + currentLocation.w > other.GetX()-25.0f&&
            GetY() < other.GetY() + other.currentLocation.h&&
            GetY() + currentLocation.h > other.GetY());
}

