#include <SDL.h>
#include <SDL_image.h>
#include "Entity.hpp"

struct coordinates{
    int x_coord;
    int y_coord;
};

class obstacles : public Entity{ 
    private:
    SDL_Texture* ptr;
    coordinates indexes[2]; //array stores the two indexes of the random obstacles
    int count;
    public:
    obstacles();
    obstacles(SDL_Texture* _ptr);
    coordinates getValue(int arr[][16]); //function receives the graph reference and generates a random number
};
