#ifndef _GAME_
#define _GAME_
#include <SDL2/SDL.h>
#include <vector>
#include "GameObject.h"
#include "InputManager.h"

class Game
{
public:
    Game();
    ~Game();

    void run();
    Uint64 getCurrentMillis();
    
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *window_surface;
    bool isRunning;
    std::vector<GameObject*> gameObjects;
    InputManager inputManager;
    
};

#endif