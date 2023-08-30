#include <iostream>
#include "Game.h"


Game::Game()
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("SDL2 Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              680, 480, 0);
    if (!window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    window_surface = SDL_GetWindowSurface(window);

    if (!window_surface)
    {
        std::cout << "Failed to get window's surface\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

Game::~Game()
{
    SDL_FreeSurface(window_surface);
    SDL_DestroyWindow(window);
}

void Game::run()
{
    const int targetFrameRate = 60;
    const float targetFrameTime = 1000.0f / targetFrameRate;
    Uint32 prevTime = getCurrentMillis();
    Uint32 frameTime = NULL;
    Uint32 frameEndTime = NULL;
    int delayTime = NULL;

    bool isRunning = true;

    while (isRunning)
    {
        Uint32 frameStartTime = getCurrentMillis();

        inputManager.update();
        if (inputManager.isKeyPressed(SDLK_ESCAPE) || inputManager.doQuit())
        {
            isRunning = false;
        }
       
        frameEndTime = getCurrentMillis();
        frameTime = frameEndTime - frameStartTime;

        delayTime = static_cast<int>(targetFrameTime - frameTime);
        std::cout << delayTime << std::endl;
        if(delayTime > 0)
        {
            SDL_Delay(delayTime);
        }
    }
    
}

Uint32 Game::getCurrentMillis()
{
    return SDL_GetTicks64();
}

