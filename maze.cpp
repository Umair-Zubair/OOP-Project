#include "maze.hpp"
#include <random>

maze::maze(){
    //overloaded constructor called whenever a new frame is created in main
    //initalizes whole array to 0
    for (int row=0;row<width;row++){
        for (int col=0;col<height;col++){
            graph[row][col]=0;
        }
    }
}

void maze::firstFrame(){    //this function makes the first fram of the maze
//for now we will build on this frame only, once it is perfected we will proceed with other frames
    for (int row=0;row<height;row++){ 
        switch (row){   //hard coded rows to draw the walls
        //graph[row][col] is set to 1 wherever walls need to be drawn
        //these coordinates will also be used to check if the player is making a valid move
        case(0):
            graph[row][4]=1;
            graph[row][6]=1;
            break;
        case(1):
            for (int col=0;col<width;col++){
                if (col!=5){
                    graph[row][col]=1;
                }
            }
            break;
        case(4):
            for (int col=0;col<width;col++){
                if (col!=3 && col!=4){
                    graph[row][col]=1;
                }
            }
            break;
        case(5):
            graph[row][2]=1;
            graph[row][5]=1;
            break;
        case(6):
            graph[row][2]=1;
            graph[row][5]=1;
            break;
        case(7):
            graph[row][2]=1;
            graph[row][5]=1;
            break;
        }
    }
    placeObstacles(); //obstacles function is called to place 2 random obstacles in the frame
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