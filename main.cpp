#pragma once
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
#include "music.hpp"
#include "frame.hpp"

using namespace std;
// g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -o main
// Please look at command for mingw and sdl installation locaton.(For group members.)
// command for compilation.

const int WIDTH = 1200, HEIGHT = 675;


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
    SDL_Texture* greenTile = window.loadTexture("obstacle.png");
    SDL_Texture* EnemyHealth = window.loadTexture("graphics/Health.png");
    SDL_Texture* PlayerHealth = window.loadTexture("graphics/playerHealth.png");
    SDL_Texture* gameOver = window.loadTexture("gameOverScreen.jpg");
    std::vector<Enemy> enemies;
    // need to make a loop for game running so that window stays popped up.
    Player player1(500, 600, playerModel);
    Enemy enemy1(900, 300, enemyModel);
    showHealth health(1105,30,EnemyHealth);
    showHealth player_Health(20,30,PlayerHealth);
    
    Frame generate(Tile,greenTile);
    vector<vector<Entity>> allFrames = generate.renderFrame();
    vector<Entity> wall = allFrames[0];
    vector<Entity> wall2 = allFrames[2];
    vector<Entity> wall3 = allFrames[4];
    vector<Entity> firstObstacles = allFrames[1];
    vector<Entity> secondObstacles = allFrames[3];
    vector<Entity> thirdObstacles = allFrames[5];

    enemies.push_back(enemy1);
    
    //First Frame
    //gameState game(Tile,window);
    //maze maze1(Tile);
    //vector<Entity> wall;
    //wall = maze1.firstFrame();

    //Second frame
    //maze maze2(Tile);
    //vector<Entity> wall2;
    //wall2 = maze2.secondFrame();
    
    //Third frame
    //maze maze3(Tile);
    //vector<Entity> wall3;
    //wall3 = maze3.thirdFrame();


    vector<Entity> maze_frame = wall;
    vector<Entity> maze_obstacles = firstObstacles;
    vector<Entity> maze_enemies;
    
    bool gameRunning = true;
    bool attackAnimate = false;
    int startTime = SDL_GetTicks();
    string direction = "Up";
    int frame = 0;

    SDL_Event event;
    if (startGame){
        BackgroundMusic music("bgMusic.mp3");
        music.play(-1);
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
                        player1.moveup(maze_frame,maze_obstacles, enemy1);
                        direction = "Up";
                        break;
                    case SDLK_s:
                    // down
                        player1.movedown(maze_frame,maze_obstacles, enemy1);
                        direction = "Down";
                        break;
                    case SDLK_a:
                    // left
                        player1.moveleft(maze_frame,maze_obstacles, enemy1);
                        direction = "Left";
                        break;
                    case SDLK_d:
                    // right
                        player1.moveright(maze_frame,maze_obstacles, enemy1);
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
            std::cout << player1.getX() << std::endl;
            if(frame == 0){
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                    //cout<<maze_obstacles[i].GetX() << " " <<maze_obstacles[i].GetY() << endl;
                }
            } 
            //RENDERING SECOND WALL
            else if(player1.getX() >=1120){
                maze_frame = wall2;
                maze_obstacles = secondObstacles;
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                    //cout<<maze_obstacles[i].GetX() << " " <<maze_obstacles[i].GetY() << endl;
                }
            }    
            if (player1.getX()>=1120){
            //RENDERING THIRD WALL
                maze_frame = wall3;
                maze_obstacles = thirdObstacles;
                for(int i =0; i<maze_frame.size(); i++){
                    window.render(maze_frame[i]);
                } 
                for (int i = 0;i<maze_obstacles.size();i++){
                    window.render(maze_obstacles[i]);
                    //cout<<maze_obstacles[i].GetX() << " " <<maze_obstacles[i].GetY() << endl;
                }
            } 
            // for (auto& enemy : enemies) {
            enemy1.moveTowardsPlayer(player1, player_Health , wall, firstObstacles);
            if (enemy1.getCurrentHealth() > 0){
                window.render(health);
                window.render(enemy1);
            }

            if(player1.getCurrentHealth() > 0){
                window.render(player1);
                window.render(player_Health);
                window.display();
            }
            else{
                gameRunning = false;
                showGameOverScreen(window,gameOver,gameRunning);
            }
            

        }
    }    
    // Rough to see how to display a window in SDL.
    // Need to run SDL renderer and SDL rect for sprites.
    // need to wrok on the mazes and then display them.
    // window.cleanUp();
    SDL_Quit();
}
