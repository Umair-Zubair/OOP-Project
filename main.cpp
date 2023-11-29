#include <iostream>
//#include<SDL2/SDL.h>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"

using namespace std;
// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
// Please look at command for mingw and sdl installation locaton.(For group members.)
// command for compilation.

const int WIDTH = 800, HEIGHT = 600;

/*void renderBrownTile(SDL_Renderer* renderer, int x, int y, int tileWidth, int tileHeight) {
    SDL_Surface* surface = SDL_LoadBMP("brownTile.bmp"); // Load brownTile.bmp (assuming it's a BMP file)
    if (!surface) {
        std::cout << "Failed to load brownTile.bmp: " << SDL_GetError() << std::endl;
        // Handle error
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    SDL_Rect destRect = { 0, 0, 100, 0}; // Destination rectangle for rendering
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);

    SDL_DestroyTexture(texture);
}*/

/*int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;

    // SDL initialization
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Create a window
    window = SDL_CreateWindow("Render Brown Tile", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    // Create a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    // Render the brown tile at specific coordinates (e.g., x = 100, y = 100) with width and height
    //renderBrownTile(renderer, 0, 0, 100, 75); // Assuming a tile size of 32x32 pixels

    SDL_RenderPresent(renderer);

    // Delay to see the rendered image (you might have game loop here)
    SDL_Delay(3000);

    RenderWindow window("Test", 800, 600);
    // Load a texture on the screen.
    //SDL_Texture* playerModel = window.loadTexture("idle_model_1.png");
    SDL_Texture* playerModel = window.loadTexture("brownTile.bmp");
    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}*/

#include "game.hpp"

int main(int argc, char *argv[]){
    Game game;
    srand(time(NULL));
    if( !game.init() ){
		printf( "Failed to initialize!\n" );
        return 0;
	}
		//Load media
    if( !game.loadMedia() ){
        printf( "Failed to load media!\n" );
        return 0;
    }

    game.run();
    game.close();

    return 0;
}

