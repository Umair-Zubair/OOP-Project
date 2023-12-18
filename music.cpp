#pragma once

#include "Music.hpp"

// Constructor for the BackgroundMusic class
BackgroundMusic::BackgroundMusic(const char* theFile) {
    // Initialize SDL Audio
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }

    // Load music from the provided file
    music = Mix_LoadMUS(theFile);
    if (music == nullptr) {
        std::cerr << "Failed to load music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
}

// Destructor for the BackgroundMusic class
BackgroundMusic::~BackgroundMusic() {
    // Free the loaded music and close SDL_audio and SDL_mixer
    Mix_FreeMusic(music);
    Mix_CloseAudio();
    SDL_Quit();
}

// Function to play the loaded music with an option for repetition
void BackgroundMusic::play(int repetition) {
    Mix_PlayMusic(music, repetition); // -1 plays music infinitely
                                       // if set to 2, it will play the bgm twice and then stop
                                       // useful for small sound effects
}

// Function to pause the currently playing music
void BackgroundMusic::pause() {
    if (Mix_PlayingMusic() != 0) {
        Mix_PauseMusic();
    }
}

// Function to resume the paused music
void BackgroundMusic::resume() {
    if (Mix_PausedMusic() != 0) {
        Mix_ResumeMusic();
    }
}
