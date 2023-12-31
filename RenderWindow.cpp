#include "RenderWindow.hpp"

using namespace std;

RenderWindow:: RenderWindow(const char* title, int width, int height):  window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    // we need to see if its null; give error.
    if (window == NULL){
        cout << "Window failed to init. Error: " << SDL_GetError() << endl;
    }

    // if not we create a window.
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity &_entity)
{
    // width height of player 64 pix (rn testing it. If needed change later.).
    // 112 by 185.
    SDL_Rect dst;
    SDL_Rect src;

    
    src.w = _entity.getCurrentLocation().w;
    src.h = _entity.getCurrentLocation().h;
    src.x = _entity.getCurrentLocation().x;
    src.y = _entity.getCurrentLocation().y;


    dst.x = _entity.GetX();
    dst.y = _entity.GetY();
    
    // For maze.
    if (static_cast<maze*>(&_entity) != nullptr){
        // need to store width and height of the brownTile.
        dst.w = 75;
        dst.h = 75;
    }
    else if (dynamic_cast<Player*>(&_entity) != nullptr || dynamic_cast<Enemy*>(&_entity)!=nullptr){
        dst.w = 100;
        dst.h = 100;
    } 
    else if (dynamic_cast<showHealth*>(&_entity) != nullptr) {
        dst.w = 75; 
        dst.h = 75; 
    }
    else{
        dst.w = 49;
        dst.h = 12;
    }

    // SDL_RenderCopy(renderer, _texture, NULL, NULL);
    SDL_RenderCopy(renderer, _entity.getTexture(), &src, &dst);
}

void RenderWindow::render(SDL_Texture* ptr)
{
   

    

    SDL_RenderCopy(renderer, ptr, NULL, NULL);
    // SDL_RenderCopy(renderer, _entity.getTexture(), &src, &dst);
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