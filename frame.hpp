#include <vector>
#include "Entity.hpp"
#include "maze.hpp"

class Frame{
    private:
    int frameNum;
    std::vector<std::vector<Entity>> allFrames;
    SDL_Texture* wall_ptr;
    SDL_Texture* obstacle_ptr;
    public:
    Frame(SDL_Texture* _ptr1,SDL_Texture* _ptr2);
    std::vector<std::vector<Entity>> renderFrame();
    std::vector<std::vector<Entity>> renderObstacles();
    void changeFrameNum();
}; 