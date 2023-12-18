#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>


class BackgroundMusic{
private:
    Mix_Music* music;//pointer to music file

public:
    BackgroundMusic(const char* thefile);

    ~BackgroundMusic();

    void play(int repetition);

    void pause();

    void resume();

};