#include "maze.hpp"
#include <random>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include <vector>
#include <iostream>
#include "obstacles.hpp"

maze::maze(): ptr(nullptr) , Entity(0,0,nullptr){};

maze::maze(SDL_Texture *_ptr): ptr(_ptr), Entity(0,0, nullptr){
    //overloaded constructor called whenever a new frame is created in main
    //initalizes whole array to 0
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            graph[row][col]=0;
            graph2[row][col]=0;
            graph3[row][col]=0;
        }
    }
}


std:: vector<Entity> maze::firstFrame(){    //this function makes the first fram of the maze
//for now we will build on this frame only, once it is perfected we will proceed with other frames
    std::vector<Entity> wall;
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
                    deadBoxes.push_back((Entity(x,0,ptr)));
                    x+=75;
                } 
                else if (col==8) {
                    graph[row][8]=1; wall.push_back(Entity(600,0,ptr));
                    x+=75;
                    //the player cannot go left when the pixels are x=675 and 0>y>75
                }
                else if (col==12) {
                    graph[row][12]=1; wall.push_back(Entity(900,0,ptr));
                    x+=75;
                }
            }
            x=0;
            break;
        case(1):
            for (int col=0;col<width;col++){
                if (col<8 || col>12){
                    graph[row][col] = -1; //dead box, player cant go there, obstacle and enemy cant spawn there
                }
                else if (col==8){
                    graph[row][8]=1;wall.push_back(Entity(600,75,ptr));
                }
                else if (col==12){
                    graph[row][12]=1;wall.push_back(Entity(900,75,ptr));
                }
            }
            break;
        case(2):
            for (int col=0;col<width;col++){
                if (col!=9 && col!=10 && col!=11){
                    graph[row][col] = 1;
                    wall.push_back(Entity(x,150,ptr));
                }
                x+= 75;
            } 
            x = 0;
            break;
        case(6):
            for (int col=0;col<width;col++){
                if (col<5 || col>9){
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
        for (int k=0;k<height;k++){
            for (int j=0;j<width;j++){
                if (graph[k][j]==-1){
                    int x = j*75;
                    int y = k*75;
                    wall.push_back(Entity(x,y,ptr));
                }
            }
        }
    }

    
    return wall;
}

//following 3 functions are exactly like firstFrame()
//Will be used to draw walls on specified coordinates

std:: vector<Entity> maze::secondFrame(){ 
    std::vector<Entity> secondWall;
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            graph2[row][col]=0;
        }
    }
    for (int i=0;i<height;i++){
        switch(i){
        case(0):
            for (int j=0;j<width;j++){
                graph2[i][j]=-1;
            }
            break;
        case(1):
            for (int j=0;j<width;j++){
                graph2[i][j] =1;
            } 
            break;
        case(5):
            for (int j=0;j<width;j++){
                if (j==0 || j==1 || j==2 || j==6 || j==7 || j==8 || j==9 || j==13 || j==14 || j==15){
                    graph2[i][j] =1;
                }
            }
            break;
        case(6):
            for (int j=0;j<width;j++){
                if (j==2 || j==6 || j==9 || j==13){
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                }
                else if (j<2 || j>13){
                    graph2[i][j]=-1;
                }
                else if (j==7 || j==8){
                    graph2[i][j]=-1;
                }
            }
            break;
        case(7):
            for (int j=0;j<width;j++){
                if (j==2 || j==6 || j==9 || j==13){
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                }
                else if (j<2 || j>13){
                    graph2[i][j]=-1;
                }
                else if (j==7 || j==8){
                    graph2[i][j]=-1;
                }
            }
            break;
        case(8):
            for (int j=0;j<width;j++){
                if (j==2 || j==6 || j==9 || j==13){
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                    graph2[i][j] =1;
                }
                else if (j<2 || j>13){
                    graph2[i][j]=-1;
                }
                else if (j==7 || j==8){
                    graph2[i][j]=-1;
                }
            }
            break;
        }
    } 
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            if (graph2[row][col]==1 || graph2[row][col]==-1){
                int x = col*75;
                int y = row*75;
                secondWall.push_back(Entity(x,y,ptr));
            }
        }
    }


    return secondWall;
}

std::vector<Entity> maze::thirdFrame(){
    std::vector<Entity> thirdWall;
    for (int i=0;i<height;i++){
        switch(i){
            case(0):
                for (int j=0;j<width;j++){
                if (j==2 || j==6 || j==9 || j==13){
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                }
                else if (j<2 || j>13){
                    graph3[i][j]=-1;
                }
                else if (j==7 || j==8){
                    graph3[i][j]=-1;
                }
                }
                break;
            case(1):
            for (int j=0;j<width;j++){
                if (j==2 || j==6 || j==9 || j==13){
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                    graph3[i][j] =1;
                }
                else if (j<2 || j>13){
                    graph3[i][j]=-1;
                }
                else if (j==7 || j==8){
                    graph3[i][j]=-1;
                }
                }
                break;
            case(2):
                for (int j=0;j<width;j++){
                    if (j==3 || j==4 || j==5 || j==10 || j==11 || j==12){
                        continue;
                    }
                    else{
                        graph3[i][j]=1;
                    }
                }
                break;
            case(6):
                for (int j=0;j<width;j++){
                    if (j<=3 || j>=12){
                        graph3[i][j]=1;
                    }
                }
                break;
            case(7):
                for (int j=0;j<width;j++){
                    if (j==3 || j==12){
                        graph3[i][j]=1;
                    }
                    else if (j<3 || j>12){
                        graph3[i][j]=-1;
                    }
                }
                break;
            case(8):
                for (int j=0;j<width;j++){
                    if (j==3 || j==12){
                        graph3[i][j]=1;
                    }
                    else if (j<3 || j>12){
                        graph3[i][j]=-1;
                    }
                }
                break;
        }
    }
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            if (graph3[row][col]==1 || graph3[row][col]==-1){
                int x = col*75;
                int y = row*75;
                thirdWall.push_back(Entity(x,y,ptr));
            }
        }
    }

    return thirdWall;
}


//copy constructor for obstacles
maze::maze(const maze &m, SDL_Texture *_ptr,int frame):ptr(_ptr), Entity(0,0, nullptr){
    for (int row=0;row<height;row++){
        for (int col=0;col<width;col++){
            graph[row][col]=0;
            graph2[row][col]=0;
            graph3[row][col]=0;
        }
    } 
    if (frame==0){
        for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                graph[i][j] = m.graph[i][j];
            }
        }
    }
    else if (frame==1){
        for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                graph2[i][j] = m.graph2[i][j];
            }
        }
    }
    else if (frame==2){
        for (int i=0;i<height;i++){
            for (int j=0;j<width;j++){
                graph3[i][j] = m.graph3[i][j];
            }
        }
    }
}


int(*maze::getGraph(int x))[height][width] {
    switch (x) {
        case 0:
            return &graph;
        case 1:
            return &graph2;
        case 2:
            return &graph3;
        default:
            return nullptr;
    }
} 