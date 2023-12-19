#include <vector>
#include "maze.hpp"
#include "obstacles.hpp"

class Frame : public maze{
    private:
    std::vector<std::vector<Entity>> allFrames;
    SDL_Texture* wall_ptr;
    SDL_Texture* obstacle_ptr;
    int frameNum;
    public:
    Frame(SDL_Texture* _ptr1,SDL_Texture* _ptr2);
    std::vector<std::vector<Entity>> renderFrame();
}; 