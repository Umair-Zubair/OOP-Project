#include "showHealth.hpp"

showHealth::showHealth(float _x, float _y, SDL_Texture* _ptr): Entity(_x,_y,_ptr){
    change_src(0,31,75,75);
    
}

void showHealth::changeHealth(int health){
    if (health == 75){
        change_src(80,31,75,75);
    }
    else if (health == 50){
        change_src(160,31,75,75);
    }
    else if (health == 25){
        change_src(240,31,75,75);
    }
}