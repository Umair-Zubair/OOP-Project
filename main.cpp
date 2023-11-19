#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
// Please look at command for mingw and sdl installation locaton.(For group members.)
// command for compilation.

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[] )
{
    SDL_Init( SDL_INIT_EVERYTHING );

    SDL_Window *window = SDL_CreateWindow( "Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );

    if ( NULL == window )
    {
        std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }

    SDL_Event windowEvent;
    //SDL_SetRenderDrawColor(renderer,0,255,0,255);

    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            { break; }
        }
    }

    SDL_DestroyWindow( window );
    SDL_Quit( );

    return EXIT_SUCCESS;
    // Rough to see how to display a window in SDL.
    // Need to run SDL renderer and SDL rect for sprites.
    // need to wrok on the mazes and then display them.
}