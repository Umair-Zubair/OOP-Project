#include <iostream>
//#include<SDL2/SDL.h>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
//#include "maze.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include <vector>

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

// #include "game.hpp"

// int main(int argc, char *argv[]){
    
//     Game game;
//     srand(time(NULL));
//     if( !game.init() ){
// 		printf( "Failed to initialize!\n" );
//         return 0;
// 	}
// 		//Load media
//     if( !game.loadMedia() ){
//         printf( "Failed to load media!\n" );
//         return 0;
//     }

//     game.run();
//     game.close();

//     return 0;
// }

int main( int argc, char *argv[] )
{
   
    // if ( NULL == window )
    // {
    //     std::cout << "Could not create window: " << SDL_GetError( ) << std::endl;
    //     return 1;
    // }
    // SDL_Event windowEvent;
    // //SDL_SetRenderDrawColor(renderer,0,255,0,255);
    // while ( true )
    // {
    //     if ( SDL_PollEvent( &windowEvent ) )
    //     {
    //         if ( SDL_QUIT == windowEvent.type )
    //         { break; }
    //     }
    // }
    // SDL_DestroyWindow( window );
    // SDL_Quit( );
    // return EXIT_SUCCESS;
    // // Rough to see how to display a window in SDL.
    // // Need to run SDL renderer and SDL rect for sprites.
    // // need to wrok on the mazes and then display them.
    // NEED TO GIVE ERROR IF PNG LOADS OR NOT.
    if (!(IMG_INIT_PNG)){
        cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;
    }
    
    SDL_Event windowEvent;
    //SDL_SetRenderDrawColor(renderer,0,255,0,255);
    RenderWindow window("Test", 1200, 675);
    // Load a texture on the screen.
    //SDL_Texture* playerModel = window.loadTexture("graphics/idle_model_1.png");
    //SDL_Texture* Tile = window.loadTexture("greyTile.jpg");
    SDL_Texture* bg = window.loadTexture("bg.png");
    SDL_Texture* playerModel = window.loadTexture("graphics/WarriorSpriteSheet.png");
    SDL_Texture* Tile = window.loadTexture("graphics/Wall.png");
    SDL_Texture* enemyModel = window.loadTexture("graphics/player.png");
    // need to make a loop for game running so that window stays popped up.
    Player player1(500, 600, playerModel);
    Enemy enemy1(0, 300, enemyModel);

    //First Frame
    maze maze1(Tile);
    vector<Entity> wall;
    wall = maze1.firstFrame();

    //Second frame
    maze maze2(Tile);
    vector<Entity> wall2;
    wall2 = maze2.secondFrame();
    
    //Third frame
    maze maze3(Tile);
    vector<Entity> wall3;
    wall3 = maze3.thirdFrame();

    bool gameRunning = true;
    bool attackAnimate = false;
    int startTime = SDL_GetTicks();
    SDL_Event event;
    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                gameRunning = false;
            }
            else if (event.type == SDL_KEYDOWN)
        {
            // Handle key presses
            switch (event.key.keysym.sym)
            {
                case SDLK_w:
                // up
                    player1.moveup(wall);

                    break;
                case SDLK_s:
                // down
                    player1.movedown(wall);
                    break;
                case SDLK_a:
                // left
                    player1.moveleft(wall);
                    break;
                case SDLK_d:
                // right
                    player1.moveright(wall);
                    break;
                case SDLK_k:
                    attackAnimate = true;
                    startTime = SDL_GetTicks();
                    // player1.AttackUp();
                    break;
            }



            // Render the enemy
        }
        }
        // movement detection and conditions.
        enemy1.moveAutomaticallyTowardsPlayer(player1, maze1);
        player1.AttackUpAnimation(attackAnimate, startTime);

        

        window.clear();

        
        window.render(bg);
        
        //RENDERING FIRST WALL
        // this is to render each wall pixel on the screen.
        for(int i =0; i<wall.size(); i++){
            window.render(wall[i]);
        }

        //RENDERING SECOND WALL
        // for (int i=0;i<wall2.size();i++){
        //     window.render(wall2[i]);
        // } 

        //RENDERING THIRD WALL
        // for (int i=0;i<wall3.size();i++){
        //     window.render(wall3[i]);
        // } 

        window.render(player1);
        window.render(enemy1);
        window.display();
    }
   
    // Rough to see how to display a window in SDL.
    // Need to run SDL renderer and SDL rect for sprites.
    // need to wrok on the mazes and then display them.
    // window.cleanUp();
    SDL_Quit();
}