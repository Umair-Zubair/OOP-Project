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

    obstacles generate1(obstacle_ptr,0);
    std::vector<Entity> firstObstacles = generate1.getObstacles(m1,0);

    obstacles generate2(obstacle_ptr,1);
    std::vector<Entity> secondObstacles = generate2.getObstacles(m2,1);

    obstacles generate3(obstacle_ptr,2);
    std::vector<Entity> thirdObstacles = generate3.getObstacles(m3,2);

    //pushing them into allFrames vector according to index
    allFrames.push_back(firstFrame);
    allFrames.push_back(firstObstacles);
    allFrames.push_back(secondFrame);
    allFrames.push_back(secondObstacles);
    allFrames.push_back(thirdFrame);
    allFrames.push_back(thirdObstacles);

    return allFrames;
}
