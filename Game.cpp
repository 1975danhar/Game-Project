#include "Game.h"


Game::Game()
{
    
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Ball Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              680, 480, 0);
    if (!window)
    {
        std::cout << "Failed to create window\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
    renderer = SDL_CreateRenderer (window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cout << "Failed to create renderer\n";
        std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
        return;
    }
}

Game::~Game()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::run()
{
    // Add function Setup
    
    const int targetFrameRate = 60;
    const double targetFrameTime = 1000.0 / targetFrameRate;
    Uint64 prevTime = getCurrentMillis();
    Uint64 frameTime = 0;
    Uint64 frameEndTime = 0;
    int delayTime = 0;
    Uint64 frameStartTime = 64;
    bool isRunning = true;
    
    while (isRunning)
    {
        // Add function input
        frameStartTime = getCurrentMillis();

        inputManager.poll();
        if (inputManager.isKeyPressed(SDLK_ESCAPE) || inputManager.doQuit())
        {
            isRunning = false;
        }
        // Add function update
        frameEndTime = getCurrentMillis();
        frameTime = frameEndTime - frameStartTime;

        delayTime = static_cast<int>(targetFrameTime - frameTime);
        if(delayTime > 0)
        {
            SDL_Delay(delayTime);
        }
    }
    
}

Uint64 Game::getCurrentMillis()
{
    return SDL_GetTicks64();
}

void Game::setup()
{
    gameObjects.push_back(std::make_unique<Ball>(renderer, resourceManager));
}
