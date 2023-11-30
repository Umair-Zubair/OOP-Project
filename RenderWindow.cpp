#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "maze.hpp"
#include <iostream>
using namespace std;

RenderWindow:: RenderWindow(const char* title, int width, int height):  window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    // we need to see if its null; give error.
    if (window == NULL){
        cout << "Window failed to init. Error: " << SDL_GetError() << endl;
    }

    // if not we create a window.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &_entity)
{
    // width height of player 64 pix (rn testing it. If needed change later.).
    // 112 by 185.
    SDL_Rect src;
    src.w = _entity.getCurrentLocation().w;
    src.h = _entity.getCurrentLocation().h;
    src.x = _entity.getCurrentLocation().x;
    src.y = _entity.getCurrentLocation().y;

    SDL_Rect dst;
    dst.x = _entity.getX();
    dst.y = _entity.GetY();
    
    // For maze.
    if (static_cast<maze*>(&_entity) != nullptr){
        // need to store width and height of the brownTile.
        dst.w = 100;
        dst.h = 75;
    }
    else{
        dst.w = 128;
        dst.h = 128;
    }

    // SDL_RenderCopy(renderer, _texture, NULL, NULL);
    SDL_RenderCopy(renderer, _entity.getTexture(), &src, &dst);
}


void RenderWindow::display()
{
    SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow:: loadTexture(const char* filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filepath);

    // create error msg(safe side).

    if (texture == NULL)
    {
        std::cout << "Error loading the texture: " << SDL_GetError() <<std::endl;
    }

    return texture;
}