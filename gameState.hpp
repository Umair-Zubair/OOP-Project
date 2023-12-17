#include "maze.hpp"
#include "Entity.hpp"
#include "RenderWindow.hpp"
#include <vector>

class gameState{
    protected:
    int frame=0;
    SDL_Texture* ptr;
    RenderWindow window;
    public:
    gameState(SDL_Texture* _ptr,RenderWindow _window);
    void changeFrame(maze m1);
}; 