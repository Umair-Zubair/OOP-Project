#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "maze.hpp"
#include <vector>

struct coordinates{
    int x_coord;
    int y_coord;
};

class obstacles : public Entity{ 
    private:
    SDL_Texture* ptr;
    maze myMaze1, myMaze2, myMaze3;
    int count;
    int copyGraph[9][16];
    int obstacleCount=0;
    std::vector<std::vector<Entity>> allObstacles;
    public:
    obstacles();
    obstacles(SDL_Texture *_ptr,int frame);
    obstacles(int x, int y, SDL_Texture* _ptr);
    std::vector<Entity> getObstacles( maze& m,int x);
    coordinates getValue(); //function receives the graph reference and generates a random number 
}; 
