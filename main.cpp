#include <iostream>
//#include<SDL2/SDL.h>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "maze.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include <vector>
#include <string>
#include "gameState.hpp"
#include "showHealth.hpp"

using namespace std;
// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
// Please look at command for mingw and sdl installation locaton.(For group members.)
// command for compilation.

const int WIDTH = 1200, HEIGHT = 675;

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

bool showWelcomeScreen(RenderWindow& window) {
    SDL_Texture* welcomeImage = window.loadTexture("welcome.jpg");

    bool welcomeScreenRunning = true;
    SDL_Event welcomeEvent;
    
    while (welcomeScreenRunning) {
        while (SDL_PollEvent(&welcomeEvent)) {
            if (welcomeEvent.type == SDL_QUIT) {
                return false; 
            } else if (welcomeEvent.type == SDL_KEYDOWN) {
                switch (welcomeEvent.key.keysym.sym) {
                    case SDLK_RETURN:
                        return true; 
                    case SDLK_ESCAPE:
                        return false; 
                    default:
                        break;
                }
            }
        }

        window.clear();
        window.render(welcomeImage);
        window.display();
    }



    return true;
}

void showGameOverScreen(RenderWindow &window, SDL_Texture *gameOverTexture, bool &gameOver) {
    SDL_Event event;
    bool showScreen = true;

    while (showScreen) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                showScreen = false;
                gameOver = true; 
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    showScreen = false; 
                    gameOver = true; 
                }
            }
        }

        window.clear();
        window.render(gameOverTexture);
        window.display();
    }
}

int main( int argc, char *argv[] )
{
   
    if (!(IMG_INIT_PNG)){
        cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;
    }
    
    SDL_Event windowEvent;
    //SDL_SetRenderDrawColor(renderer,0,255,0,255);
    RenderWindow window("Test", 1200, 675);
    bool startGame = showWelcomeScreen(window);
    // Load a texture on the screen.
    //SDL_Texture* playerModel = window.loadTexture("graphics/idle_model_1.png");
    //SDL_Texture* Tile = window.loadTexture("greyTile.jpg");
    SDL_Texture* bg = window.loadTexture("greenBG.jpg");
    SDL_Texture* playerModel = window.loadTexture("graphics/WarriorSpriteSheet.png");
    SDL_Texture* Tile = window.loadTexture("graphics/Wall.png");
    SDL_Texture* enemyModel = window.loadTexture("graphics/SkeletonSpriteSheet.png");
    SDL_Texture* greenTile = window.loadTexture("fire .png");
    SDL_Texture* EnemyHealth = window.loadTexture("graphics/Health.png");
    SDL_Texture* gameOver = window.loadTexture("gameOverScreen.jpg");
    std::vector<Enemy> enemies;
    // need to make a loop for game running so that window stays popped up.
    Player player1(500, 600, playerModel);
    Enemy enemy1(100, 300, enemyModel);
    showHealth health(1105,30,EnemyHealth);


    enemies.push_back(enemy1);
    
    //First Frame
    //gameState game(Tile,window);
    maze maze1(Tile);
    vector<Entity> wall;
    wall = maze1.firstFrame();
    //First frame obstacle
    vector<Entity> firstObstacles;
    maze maze1obstacles(maze1,greenTile);
    firstObstacles = maze1obstacles.placeObstacles();

    //Second frame
    maze maze2(Tile);
    vector<Entity> wall2;
    wall2 = maze2.secondFrame();
    //second frame obstacle
    vector<Entity> secondObstacles;
    maze maze2obstacles(maze2,greenTile);
    secondObstacles = maze2obstacles.placeObstacles();
    
    //Third frame
    maze maze3(Tile);
    vector<Entity> wall3;
    wall3 = maze3.thirdFrame();

    bool gameRunning = true;
    bool attackAnimate = false;
    int startTime = SDL_GetTicks();
    string direction = "Up";
    SDL_Event event;
    if (startGame){
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
                if (player1.obstacleCollision()==true){
                    gameRunning = false;
                    showGameOverScreen(window,gameOver,gameRunning);
                    return 0;
                }
                switch (event.key.keysym.sym)
                    {
                    case SDLK_w:
                    // up
                        player1.moveup(wall,firstObstacles, enemy1);
                        direction = "Up";
                        break;
                    case SDLK_s:
                    // down
                        player1.movedown(wall,firstObstacles, enemy1);
                        direction = "Down";
                        break;
                    case SDLK_a:
                    // left
                        player1.moveleft(wall,firstObstacles, enemy1);
                        direction = "Left";
                        break;
                    case SDLK_d:
                    // right
                        player1.moveright(wall,firstObstacles, enemy1);
                        direction = "Right";
                        break;
                    case SDLK_k:
                        attackAnimate = true;
                        startTime = SDL_GetTicks();
                        
                        // player1.AttackUp();
                        break;
                    }  
                }
            }

            if (direction == "Up"){
                player1.AttackUpAnimation(attackAnimate, startTime, enemy1);
            }
            else if (direction == "Left"){
                player1.AttackLeftAnimation(attackAnimate, startTime, enemy1);

            }
            else if (direction == "Right"){
                player1.AttackRightAnimation(attackAnimate, startTime, enemy1);
            }
            else {
                player1.AttackDownAnimation(attackAnimate, startTime, enemy1);

            }
            health.changeHealth(enemy1.getCurrentHealth());
        
            window.clear();
            window.render(bg);
            
            //RENDERING FIRST WALL
            //this is to render each wall pixel on the screen.
            for(int i =0; i<wall.size(); i++){
                window.render(wall[i]);
            }
            for (int i=0;i<firstObstacles.size();i++){
                window.render(firstObstacles[i]);
            }

            //RENDERING SECOND WALL
            // for (int i=0;i<wall2.size();i++){
            //     window.render(wall2[i]);
            // } 

            //RENDERING THIRD WALL
            // for (int i=0;i<wall3.size();i++){
            //     window.render(wall3[i]);
            // } 

            // for (auto& enemy : enemies) {
            enemy1.moveTowardsPlayer(player1, maze1);
            if (enemy1.getCurrentHealth() > 0){
                window.render(health);
                window.render(enemy1);
            }
            // else{
            //     delete enemy1;
            // }
            
            window.render(player1);
            window.display();
        }
    }    
    // Rough to see how to display a window in SDL.
    // Need to run SDL renderer and SDL rect for sprites.
    // need to wrok on the mazes and then display them.
    // window.cleanUp();
    SDL_Quit();
}