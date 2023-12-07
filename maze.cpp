#include "maze.hpp"
#include <random>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include <vector>
#include <iostream>
maze::maze(): ptr(nullptr) , Entity(0,0,nullptr){};

maze::maze(SDL_Texture *_ptr): ptr(_ptr), Entity(0,0, nullptr){
    //overloaded constructor called whenever a new frame is created in main
    //initalizes whole array to 0
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            graph[row][col]=0;
        }
    }
}

std::vector<pixelRec> maze::getInvalid(){
    return firstFrameInvalid;
}

std:: vector<Entity> maze::firstFrame(){    //this function makes the first fram of the maze
//for now we will build on this frame only, once it is perfected we will proceed with other frames
    std:: vector<Entity> wall;
    // starting postion of the first wall in top left corner.
    float x = 0;
    float y = 0;
    //stores the pixelRect structures for all invalid move pixels in the first frame. 
    //memory will be deallocated as soon as the frame is closed
    int temp = 0;
    for (int row=0;row<height;row++){ 
        switch (row){   //hard coded rows to draw the walls
        //graph[row][col] is set to 1 wherever walls need to be drawn
        //these coordinates will also be used to check if the player is making a valid move
        case(0):
            for (int col=0;col<width;col++){
                if (col<8 || col>12){
                    graph[row][col] = -1; //dead box, player cant go there, obstacle and enemy cant spawn there
                }
                else if (col==8) {
                    graph[row][8]=1; wall.push_back(Entity(600,0,ptr));
                    //the player cannot go left when the pixels are x=675 and 0>y>75
                    for (int i=0;i<75;i++){
                        pixelRec rec; rec.x_coord = 675 ; rec.y_coord = i; firstFrameInvalid.push_back(rec);
                    }
                }
                else if (col==12) {
                    graph[row][12]=1; wall.push_back(Entity(900,0,ptr));
                    for (int i=0;i<75;i++){
                        pixelRec rec; rec.x_coord = 900 ; rec.y_coord = i; firstFrameInvalid.push_back(rec);
                    }
                }
            }
            break;
        case(1):
            for (int col=0;col<width;col++){
                if (col<8 || col>12){
                    graph[row][col] = -1; //dead box, player cant go there, obstacle and enemy cant spawn there
                }
                else if (col==8){
                    graph[row][8]=1;wall.push_back(Entity(600,75,ptr));
                    for (int i=0;i<75;i++){
                        pixelRec rec; rec.x_coord = 675 ; rec.y_coord = i; firstFrameInvalid.push_back(rec);
                    }
                }
                else if (col==12){
                    graph[row][12]=1;wall.push_back(Entity(900,75,ptr));
                    for (int i=0;i<75;i++){
                        pixelRec rec; rec.x_coord = 900 ; rec.y_coord = i; firstFrameInvalid.push_back(rec);
                    }
                }
            }
            break;
        case(2):
            for (int col=0;col<width;col++){
                if (col!=9 && col!=10 && col!=11){
                    graph[row][col] = 1;
                    wall.push_back(Entity(x,150,ptr));
                    for (int i=0;i<75;i++){
                        pixelRec rec; rec.x_coord = x+i ; rec.y_coord = 225; firstFrameInvalid.push_back(rec);
                    }
                }
                x+= 75;
            } 
            x = 0;
            break;
        case(6):
            for (int col=0;col<width;col++){
                if (col!=5 && col!=6 && col!=7 && col!=8 && col!=9){
                    graph[row][col]=1;
                    wall.push_back(Entity(x,450,ptr));
                }
                x += 75;
            } 
            x = 0;
            break;
        case(7):
            for (int col=0;col<width;col++){
                if (col<4 || col>10){
                    graph[row][col] = -1;   //inaccesible points
                }
                else if (col==4){graph[row][4]=1;wall.push_back(Entity(300,525,ptr));}
                else if (col==10){graph[row][10]=1;wall.push_back(Entity(750,525,ptr));}
            }
            break;
        case(8):
            for (int col=0;col<width;col++){
                if (col<4 || col>10){
                    graph[row][col] = -1;   //inaccesible points
                }
                else if (col==4){graph[row][4]=1;wall.push_back(Entity(300,600,ptr));}
                else if (col==10){graph[row][10]=1;wall.push_back(Entity(750,600,ptr));}
            }
            break;
        }
    }
    // for (int i=0;i<firstFrameInvalid.size();i++){
    //     std::cout << firstFrameInvalid[i].x_coord << " " << firstFrameInvalid[i].y_coord;
    // }
    placeObstacles(); //obstacles function is called to place 2 random obstacles in the frame
    return wall;
}

//following 3 functions are skeleton, will be implemented later.
//they will be exactly like firstFrame(). 
//Will be used to draw walls on specified coordinates
void maze::secondFrame(){

}

void maze::thirdFrame(){
    
}

void maze::fourthFrame(){
    
}

void maze::makeGraph(){
    if (frame==0){ // first frame 
        frame++; //incremented to ensure next time the same frame isnt drawn
        firstFrame(); // function to draw the walls of first frame is called
    }
    else if (frame==1){
        frame++;
        secondFrame();  //function to draw walls of second frame
    }
    else if (frame==2){
        frame++;
        thirdFrame();   //function to draw walls of third frame
    }
    else if (frame==3){
        frame++;
        fourthFrame();  //function to draw walls of fourth frame
    }
}

void maze::placeObstacles(){
    //there will be 2 random obstacles placed in the map
    //if the player goes on that coordinate, they lose
    int obstacleRow=0,obstacleCol=0; 
    while (obstacleCount!=2){   //this loop ensures not more than 2 obstacles are placed
        obstacleRow = rand() % 8;   //random generation of row
        obstacleCol = rand() % 8;   //random generation of col
        if (graph[obstacleRow][obstacleCount]!=1){  //condition ensures a wall is not at this coordinate
            graph[obstacleRow][obstacleCol]=2;  //if there is no wall, an obstacle is placed
            //the coordinate is set to 2, meaning an obstacle is present here and player cant go here
            obstacleCount++;    //obstacle count is increased
        }
        //this loop keeps on generating cols and rows and placing obstacles until 2 obstcales are placed
    }
}  

// void maze::placeObstacles() {

//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<int> randX(0, width - 1);
//     std::uniform_int_distribution<int> randY(0, height - 1);

//     for (int i = 0; i < 2; i++) {
//         int obstacleX = randX(gen);
//         int obstacleY = randY(gen);

//         while (graph[obstacleY][obstacleX] != 0) {
//             obstacleX = randX(gen);
//             obstacleY = randY(gen);
//         }

//         graph[obstacleY][obstacleX] = 1;
//     }
// }

bool maze::isValidMove(int x, int y) const {
    // Check if the move is within the boundaries and not hitting a wall
    if (x >= 0 && x < width && y >= 0 && y < height && graph[y][x] == 0) {
        return true;
    }
    return false;
}
