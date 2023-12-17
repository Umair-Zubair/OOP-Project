#pragma once
#include "drawing.hpp"
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
    int graph[height][width];
    int graph2[height][width];
    int graph3[height][width];
    int frame = 0;
    int obstacleCount=0;
    // SDL_Rect srcRect, moverRect;
    SDL_Texture* ptr;
    public:
    maze();
    maze(const maze &m, SDL_Texture *ptr);
    maze(SDL_Texture *ptr);
    void makeGraph();
    std::vector<Entity> firstFrame();
    std::vector<Entity> secondFrame();
    std::vector<Entity> thirdFrame();
    void fourthFrame();
    void changeFrame(int x);
    std::vector<Entity> placeObstacles();
    bool isValidMove(int x, int y) const;
    std::vector<Entity> deadBoxes;
};