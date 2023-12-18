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

float Entity::GetWidth() const{
    return currentLocation.w;
}

float Entity::GetHeight() const{
    return currentLocation.h;
}

SDL_Rect Entity::getCurrentLocation() const{
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

// code for collision.
bool Entity::checkCollision(const Entity& enemy) {
    const float collisionOffset = 25.0f;

    return (y + getCurrentLocation().h > enemy.GetY() - collisionOffset &&
            y < enemy.GetY() + enemy.getCurrentLocation().h + collisionOffset &&
            x + getCurrentLocation().w > enemy.GetX() - collisionOffset &&
            x < enemy.GetX() + enemy.getCurrentLocation().w + collisionOffset);
}


bool Entity::AttackCollision(const Entity& enemy) {
    const float collisionOffset = 35.0f;

    return (y + getCurrentLocation().h > enemy.GetY() - collisionOffset &&
            y < enemy.GetY() + enemy.getCurrentLocation().h + collisionOffset &&
            x + getCurrentLocation().w > enemy.GetX() - collisionOffset &&
            x < enemy.GetX() + enemy.getCurrentLocation().w + collisionOffset);
}
