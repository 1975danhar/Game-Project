#ifndef _BALL_
#define _BALL_
#include <SDL2/SDL.h>

#include "GameObject.h"
#include "InputManager.h"
#include "ResourceManager.h"

class Ball: private GameObject
{
public:
    Ball(SDL_Renderer* renderer, ResourceManager& rm);
    ~Ball();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;

    InputManager inputManager;
    ResourceManager resourceManager;
};

#endif