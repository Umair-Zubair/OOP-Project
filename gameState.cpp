#include "gameState.hpp"

gameState::gameState(SDL_Texture *_ptr,RenderWindow _window):frame(0),ptr(_ptr),window(_window){
    maze control(ptr);
    changeFrame(control);
}

void gameState::changeFrame(maze m1){
    if (frame==0){
        std::vector<Entity> wall;
        wall = m1.firstFrame();
        for(int i =0; i<wall.size(); i++){
            window.render(wall[i]);
        }
    }
}