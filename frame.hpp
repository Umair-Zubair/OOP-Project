#include <vector>
#include "Entity.hpp"

class Frame{
    private:
    int frameNum;
    std::vector<Entity> renderFrames;
    public:
    void renderFrame();
    void changeFrameNum();
}; 