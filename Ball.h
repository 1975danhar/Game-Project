#ifndef _BALL_
#define _BALL_
#include <SDL2/SDL.h>
#include <iostream>
#include "GameObject.h"
#include "InputManager.h"
#include "ResourceManager.h"

class Ball: public GameObject
{
public:
    Ball(SDL_Renderer* renderer, ResourceManager& rm);
    ~Ball() override;

    void update() override;
    void render() override;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *ballTexture;
    InputManager inputManager;
    ResourceManager resourceManager;
};

#endif