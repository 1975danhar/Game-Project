#ifndef _GAME_
#define _GAME_
#include <SDL2/SDL.h>
#include <vector>
#include "GameObject.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "Ball.h"

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
    bool isRunning;
    std::vector<GameObject> gameObjects;
    InputManager inputManager;
    ResourceManager resourceManager;
    void setup();
};

#endif