#include "drawing.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include <vector>

class maze: public Entity{
    protected:
    enum {width = 16, height = 9};
    int graph[width][height];
    int frame = 0;
    int obstacles[width][height];
    int obstacleCount=0;
    SDL_Rect srcRect, moverRect;
    SDL_Texture* ptr;
    public:
    maze(SDL_Texture *ptr);
    void makeGraph();
    std::vector<Entity> firstFrame();
    void secondFrame();
    void thirdFrame();
    void fourthFrame();
    void placeObstacles();
    bool isValidMove(int x, int y) const;
};