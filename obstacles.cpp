#include "obstacles.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "random"
obstacles::obstacles():ptr(nullptr),count(0),Entity(0,0,nullptr){}

obstacles::obstacles(SDL_Texture* _ptr):ptr(_ptr),count(0),Entity(0,0,nullptr){}

coordinates obstacles::getValue(int arr[][16]){
    while (count!=2)
    {
        int randomCol = rand() % 16;
        int randomRow = rand() % 9;    
        if (arr[randomRow][randomCol]==0){
            coordinates point;
            point.y_coord = randomRow;
            point.x_coord = randomCol;
            indexes[count] = point;
        } 
        count++;
    } 
    return indexes[0];
}