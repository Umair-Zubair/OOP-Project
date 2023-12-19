#include "Entity.hpp"

// Constructor for the Entity class, initializing position and texture
Entity::Entity(float _x, float _y, SDL_Texture* _ptr) : x(_x), y(_y), ptr(_ptr) {
    // Initialize the default values for the source rectangle
    currentLocation.x = 0;
    currentLocation.y = 0;
    currentLocation.w = 200;
    currentLocation.h = 400;
}

// Get the X coordinate of the entity
float Entity::GetX() const{
    return x;
}

// Get the Y coordinate of the entity
float Entity::GetY() const{
    return y;
}

// Get the width of the entity
float Entity::GetWidth() const{
    return currentLocation.w;
}

// Get the height of the entity
float Entity::GetHeight() const{
    return currentLocation.h;
}

// Get the SDL_Rect representing the current location of the entity
SDL_Rect Entity::getCurrentLocation() const{
    return currentLocation;
}

// Get the SDL_Texture pointer associated with the entity
SDL_Texture* Entity::getTexture() {
    return ptr;
}

// Change the source rectangle for rendering
void Entity::change_src(float _x, float _y, float width, float height) {
    currentLocation.x = _x;
    currentLocation.y = _y;
    currentLocation.w = width;
    currentLocation.h = height;
}

// Check for collision with another entity, considering a collision offset
bool Entity::checkCollision(const Entity& enemy) {
    const float collisionOffset = 25.0f;

    return (y + getCurrentLocation().h > enemy.GetY() - collisionOffset &&
            y < enemy.GetY() + enemy.getCurrentLocation().h + collisionOffset &&
            x + getCurrentLocation().w > enemy.GetX() - collisionOffset &&
            x < enemy.GetX() + enemy.getCurrentLocation().w + collisionOffset);
}

// Check for collision during an attack with another entity, considering a larger collision offset
bool Entity::AttackCollision(const Entity& enemy) {
    const float collisionOffset = 35.0f;

    return (y + getCurrentLocation().h > enemy.GetY() - collisionOffset &&
            y < enemy.GetY() + enemy.getCurrentLocation().h + collisionOffset &&
            x + getCurrentLocation().w > enemy.GetX() - collisionOffset &&
            x < enemy.GetX() + enemy.getCurrentLocation().w + collisionOffset);
}