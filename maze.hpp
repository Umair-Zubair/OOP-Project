#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include <vector>

struct pixelRec{    //this structure is used to define x and y values of pixels the player cant go
    int x_coord;    //each invalid pixel will be stored in a structure and kept in a vector
    int y_coord;    
};

class maze: public Entity{
    protected:
    enum {width = 16, height = 9};
    int graph[height][width], graph2[height][width], graph3[height][width], myGraph[height][width], myGraph2[height][width], myGraph3[height][width];
    int frame = 0;
    int obstacleCount=0;
    int enemyCount = 0;
    SDL_Texture* ptr;
    public:
    maze();
    maze(const maze &m, SDL_Texture *ptr,int frame);
    maze(SDL_Texture *ptr);
    std::vector<Entity> firstFrame();
    std::vector<Entity> secondFrame();
    std::vector<Entity> thirdFrame();
    void fourthFrame();
    void changeFrame(int x);
    //std::vector<Entity> placeObstacles(int place);
    std::vector<Entity> deadBoxes;
    int(*getGraph(int x))[height][width];
};