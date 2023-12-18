#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"
#include "maze.hpp"

struct coordinates{
    int x_coord;
    int y_coord;
};

class obstacles : public Entity, public maze{ 
    private:
    SDL_Texture* ptr;
    int count;
    std::vector<std::vector<Entity>> allObstacles;
    public:
    obstacles();
    obstacles(SDL_Texture* _ptr);
    std::vector<std::vector<Entity>> getObstacles();
    coordinates getValue(); //function receives the graph reference and generates a random number 
}; 
