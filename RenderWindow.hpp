#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"

class RenderWindow
{
    private:

        SDL_Window* window;
        SDL_Renderer* renderer;
    
    public:
        RenderWindow(const char* w_title,int width, int height);
        SDL_Texture* loadTexture(const char* filepath); // this function is used to load the image.
        // need to render the texture that is being loaded.
        // need to display the texture.
        void clear(); //this is to clear anything old data that renderer has currently.
        void render(Entity &_entity);// render function.
        void render(SDL_Texture* ptr);
        void display();

};