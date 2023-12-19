#include "obstacles.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "random"
#include "maze.hpp" 

obstacles::obstacles():ptr(nullptr),count(0),Entity(0,0,nullptr){}

obstacles::obstacles(SDL_Texture *_ptr,int frame):ptr(_ptr),count(frame),Entity(0,0,nullptr){};

obstacles::obstacles(int x, int y, SDL_Texture* _ptr):Entity(x,y,_ptr){
    change_src(0,0,50,50);
};

std::vector<Entity> obstacles::getObstacles( maze& m,int x){
    //there will be 2 random obstacles placed in the map
    //if the player goes on that coordinate, they lose
    std::vector<Entity> FrameObstacles;
    coordinates point;
    while (obstacleCount != 1){
        point = getValue();
        int (*graph)[9][16] = m.getGraph(x); // Access the graph array from the maze class
        if (graph != nullptr && (*graph)[point.y_coord][point.x_coord] == 0) {
            (*graph)[point.y_coord][point.x_coord] = 2;
            int x = point.x_coord * 75;
            int y = point.y_coord * 75;
            FrameObstacles.push_back(obstacles(x, y, ptr));
            obstacleCount++;
        }
    }
    return FrameObstacles;
}

coordinates obstacles::getValue(){
    coordinates point;
    int randomCol = rand() % 7 + 4; 
    int randomRow = rand() % 5 + 2; 
    point.x_coord = randomCol;
    point.y_coord = randomRow;
    return point;
}
