#pragma once
#include <iostream>
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
#include "music.hpp"
#include "frame.hpp"

using namespace std;
// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
// Please look at command for mingw and sdl installation locaton.(For group members.)
// command for compilation.

// Define the dimensions of the game window
const int WIDTH = 1200, HEIGHT = 675;

// Function to display the welcome screen and wait for user input
bool showWelcomeScreen(RenderWindow& window) {
    // Load the texture for the welcome screen
    SDL_Texture* welcomeImage = window.loadTexture("welcome.jpg");

    // Set up variables for the welcome screen loop
    bool welcomeScreenRunning = true;
    SDL_Event welcomeEvent;

    // Loop until user input is received
    while (welcomeScreenRunning) {
        // Handle SDL events
        while (SDL_PollEvent(&welcomeEvent)) {
            // Quit the game if the window is closed
            if (welcomeEvent.type == SDL_QUIT) {
                return false; 
            } 
            // Check for key presses
            else if (welcomeEvent.type == SDL_KEYDOWN) {
                switch (welcomeEvent.key.keysym.sym) {
                    // If Enter is pressed, start the game
                    case SDLK_RETURN:
                        return true; 
                    // If Escape is pressed, quit the game
                    case SDLK_ESCAPE:
                        return false; 
                    default:
                        break;
                }
            }
        }

        // Clear the window, render the welcome image, and display the window
        window.clear();
        window.render(welcomeImage);
        window.display();
    }

    // This return statement is not reached, but included for completeness
    return true;
}

// Function to display the game over screen and handle user input
void showGameOverScreen(RenderWindow &window, SDL_Texture *gameOverTexture, bool &gameOver) {
    // Set up variables for the game over screen loop
    SDL_Event event;
    bool showScreen = true;

    // Loop until user input is received
    while (showScreen) {
        // Handle SDL events
        while (SDL_PollEvent(&event)) {
            // Quit the game if the window is closed
            if (event.type == SDL_QUIT) {
                showScreen = false;
                gameOver = true; 
            }
            // Check for key presses
            else if (event.type == SDL_KEYDOWN) {
                // If Escape is pressed, quit the game
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    showScreen = false; 
                    gameOver = true; 
                }
            }
        }

        // Clear the window, render the game over image, and display the window
        window.clear();
        window.render(gameOverTexture);
        window.display();
    }
}


void showGameWonScreen(RenderWindow &window, SDL_Texture *gameWonTexture, bool &gameWon) {
    SDL_Event event;
    bool showScreen = true;

    while (showScreen) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                showScreen = false;
                gameWon = true; 
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    showScreen = false; 
                    gameWon = true; 
                }
            }
        }

        window.clear();
        window.render(gameWonTexture);
        window.display();
    }
}
// need to make a check if the user is selecting the correct path to go to the next frame.
bool FrameChecker(int frameNo, Player player){
    if (frameNo == 0 && player.getX() >=1120 && (player.getY() >=225 || player.getY() <=975)){
        return true;
    }

    else if (frameNo == 1 && player.getY() >=620 ){
        return true;
    }
    else if (frameNo == 2 && player.getX()>= 1120 && (player.getY() >=225 || player.getY() <=975)){
        return true;
    }
    else{return false;}
    
}


int main( int argc, char *argv[] )
{
    // Initialize SDL image loading
    if (!(IMG_INIT_PNG)){
        cout << "IMG_init has failed. Error: " << SDL_GetError() << endl;
    }

    // Set up SDL event handling and create the game window
    SDL_Event windowEvent;
    RenderWindow window("Test", 1200, 675);

    // Display the welcome screen and start the game if user presses Enter
    bool startGame = showWelcomeScreen(window);

    // Load textures for various game elements
    SDL_Texture* bg = window.loadTexture("greenBG.jpg");
    SDL_Texture* playerModel = window.loadTexture("graphics/WarriorSpriteSheet.png");
    SDL_Texture* Tile = window.loadTexture("graphics/Wall.png");
    SDL_Texture* enemyModel = window.loadTexture("graphics/SkeletonSpriteSheet.png");
    SDL_Texture* greenTile = window.loadTexture("obstacle.png");
    SDL_Texture* EnemyHealth = window.loadTexture("graphics/Health.png");
    SDL_Texture* PlayerHealth = window.loadTexture("graphics/playerHealth.png");
    SDL_Texture* gameOver = window.loadTexture("gameOverScreen.jpg");
    SDL_Texture* gameWon = window.loadTexture("graphics/GameWon.jpeg");
    std::vector<Enemy> enemies;
    Player player1(500, 600, playerModel);
    Enemy enemy1(900, 300, enemyModel);
    showHealth health(1105,30,EnemyHealth);
    showHealth player_Health(20,30,PlayerHealth);
    
    // Create the maze frame and obstacles
    Frame generate(Tile,greenTile);
    vector<vector<Entity>> allFrames = generate.renderFrame();
    vector<Entity> wall = allFrames[0];
    vector<Entity> wall2 = allFrames[2];
    vector<Entity> wall3 = allFrames[4];
    vector<Entity> firstObstacles = allFrames[1];
    vector<Entity> secondObstacles = allFrames[3];
    vector<Entity> thirdObstacles = allFrames[5];

    // Add an enemy to the vector
    enemies.push_back(enemy1);

    // Initialize vectors for maze elements
    vector<Entity> maze_frame = wall;
    vector<Entity> maze_obstacles = firstObstacles;
    vector<Entity> maze_enemies;
    
    // Set up game loop variables
    bool gameRunning = true;
    bool attackAnimate = false;
    int startTime = SDL_GetTicks();
    string direction = "Up";
    int frame = 0;

    SDL_Event event;

    // If the game is started from the welcome screen
    if (startGame){
        // Play background music
        BackgroundMusic music("bgMusic.mp3");
        music.play(-1);

        // Main game loop
        while (gameRunning)
        {
            // Handle SDL events
            while (SDL_PollEvent(&event))
            {
                // Quit the game if the window is closed
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
                // Handle key presses
                else if (event.type == SDL_KEYDOWN)
                {
                    // Check for obstacle collision, end the game if true
                    if (player1.obstacleCollision()==true){
                        gameRunning = false;
                        showGameOverScreen(window,gameOver,gameRunning);
                        return 0;
                    }
                    
                    // Handle player movement and attack events
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_w:
                            // Move up
                            player1.moveup(maze_frame,maze_obstacles, enemy1);
                            direction = "Up";
                            break;
                        case SDLK_s:
                            // Move down
                            player1.movedown(maze_frame,maze_obstacles, enemy1);
                            direction = "Down";
                            break;
                        case SDLK_a:
                            // Move left
                            player1.moveleft(maze_frame,maze_obstacles, enemy1);
                            direction = "Left";
                            break;
                        case SDLK_d:
                            // Move right
                            player1.moveright(maze_frame,maze_obstacles, enemy1);
                            direction = "Right";
                            break;
                        case SDLK_k:
                            // Initiate attack animation
                            attackAnimate = true;
                            startTime = SDL_GetTicks();
                            break;
                    }  
                }
            }

            // Perform attack animation based on player direction
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

            // Update enemy health display
            health.changeHealth(enemy1.getCurrentHealth());
        
            // Clear the window and render the background
            window.clear();
            window.render(bg);
            // First wall render
            if(frame == 0){
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                }
                if (FrameChecker(frame, player1)){
                    player1.setX(5);
                    player1.setY(300);
                    frame +=1;
                }
            } 
            //RENDERING SECOND WALL
            else if(frame == 1){
                maze_frame = wall2;
                maze_obstacles = secondObstacles;
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                }
                if (FrameChecker(frame, player1)){
                    // need to check player location and update his values accordingly.
                    if (player1.getX() >= 230 && player1.getX() <= 450){
                        player1.setX(300);
                        player1.setY(20);
                    }
                    else{
                        player1.setX(825);
                        player1.setY(20);
                    }
                    frame +=1;
                }
                
            }    
            else if (frame == 2){
            //RENDERING THIRD WALL
                maze_frame = wall3;
                maze_obstacles = thirdObstacles;
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                }
                if (FrameChecker(frame, player1)){
                    showGameWonScreen(window,gameWon,gameRunning);
                    gameRunning = false;
                    
                }
            } 

            // Move and render the enemy, update player health
            enemy1.moveTowardsPlayer(player1, player_Health , wall, firstObstacles);
            if (enemy1.getCurrentHealth() > 0){
                window.render(health);
                window.render(enemy1);
            }

            // Render the player and player health if player is alive
            if(player1.getCurrentHealth() > 0){
                window.render(player1);
                window.render(player_Health);
                window.display();
            }
            // If player is dead, end the game
            else{
                gameRunning = false;
                showGameOverScreen(window,gameOver,gameRunning);
            }
        }
    }    

    // Quit SDL
    SDL_Quit();

    // End of the program
    return 0;
}