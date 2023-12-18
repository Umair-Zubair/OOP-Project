#include "obstacles.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "random"
#include "maze.hpp" 

obstacles::obstacles():ptr(nullptr),count(0),Entity(0,0,nullptr){}

obstacles::obstacles(SDL_Texture* _ptr):ptr(_ptr),count(0),Entity(0,0,nullptr){}

coordinates obstacles::getValue(){
    coordinates point;
    int randomCol = rand() % 7 + 4; 
    int randomRow = rand() % 5 + 2; 
    point.x_coord = randomCol;
    point.y_coord = randomRow;
    return point;
}