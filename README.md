#OOP PROJECT
# Maze Warrior
To compile and play the game:
1) Clone the repository to your PC.
2) For windows use this command to compile the code: g++ *.cpp -IC:\mingw_dev_lib\include\SDL2 -LC:\mingw_dev_lib\lib -w-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -o output
3) After the code compiles, enter this command to start the game: .\output.exe

## Overview
"Maze Warrior" is an engaging 2D RPG game where players embark on an adventure through challenging handcrafted mazes filled with armed enemies and obstacles. The goal is to survive, navigate through the maze, defeat enemies, and reach the finish line within a set time limit.

## Features
- **Maze Exploration:** Explore unique handcrafted maze layouts filled with challenges, enemies, death traps, and obstacles.
- **Enemy Encounters:** Engage in turn-based combat with armed enemies using various skills and strategies.
- **Visual Style:** Enjoy detailed and colorful 2D visuals that bring the mazes and enemies to life.
- **Player Information:** Manage the player's health, ammunition, and weapons to overcome obstacles.

## Tentative Classes
- **Maze Class:** Represents the maze in the game, including layout, traps, and obstacles.
- **Player Class:** Manages the player's location, health, and actions.
- **Health Class:** Handles player and enemy health, including methods to update health.
- **Enemy Class:** Represents enemies in the game, controlling their movement and attacks.
- **Enemy Health Class:** Manages the health of each enemy, increasing difficulty as the game progresses.
- **Game State Class:** Keeps track of the game state, updating based on player actions and displaying win/lose messages.

## Gameplay
1. **Launching the Game:**
   - Open the game application.
   - Navigate through the main menu to start a new game.

2. **Maze Exploration:**
   - Explore the maze layout, encountering enemies, obstacles, and traps.
   - Use on-screen controls or keyboard input to move through the maze.

3. **Enemy Encounters:**
   - Engage in turn-based combat with enemies by moving into their tiles.
   - Choose actions during your turn, such as attacking or using skills.

4. **Game Progression:**
   - Reach the finish line within the time limit to win.
   - Manage player health to avoid losing the game.

5. **Ending the Game:**
   - Receive win or lose messages based on game outcomes.
   - Restart the game or return to the main menu.
  
## References
1. https://foozlecc.itch.io/lucifer-skeleton-grunt-enemy
2. https://www.youtube.com/watch?v=WK_ojz7TOdM&list=PL2RPjWnJduNmXHRYwdtublIPdlqocBoLS&index=6
3. https://foozlecc.itch.io/lucifer-warrior
4. https://youtu.be/OuRvOCf9mJ4?si=nlViL6yRO59AdWR-

