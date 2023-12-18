#include "frame.hpp"
void Frame::changeFrameNum(){
    frameNum++;
    renderFrame();
}

Frame::Frame(SDL_Texture* _ptr1,SDL_Texture* _ptr2):frameNum(0),wall_ptr(_ptr1),obstacle_ptr(_ptr2){};

std::vector<std::vector<Entity>> Frame::renderFrame(){
    //generating first maze
    maze m1(wall_ptr);
    std::vector<Entity> firstFrame = m1.firstFrame();
    //generating second maze
    maze m2(wall_ptr);
    std::vector<Entity> secondFrame = m2.secondFrame();
    //generating third maze
    maze m3(wall_ptr);
    std::vector<Entity> thirdFrame = m3.thirdFrame();

    maze maze1obstacle(m1,obstacle_ptr);
    std::vector<Entity> firstObstacles;
    firstObstacles = maze1obstacle.placeObstacles(0);

    maze maze2obstacles(m2,obstacle_ptr);
    std::vector<Entity> secondObstacles;
    secondObstacles = maze2obstacles.placeObstacles(1);

    maze maze3obstacles(m3,obstacle_ptr);
    std::vector<Entity> thirdObstacles;
    thirdObstacles = maze3obstacles.placeObstacles(2);
    //pushing them into allFrames vector according to index
    allFrames.push_back(firstFrame);
    allFrames.push_back(firstObstacles);
    allFrames.push_back(secondFrame);
    allFrames.push_back(secondObstacles);
    allFrames.push_back(thirdFrame);
    allFrames.push_back(thirdObstacles);

    return allFrames;
}

