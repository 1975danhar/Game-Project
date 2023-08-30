#include <SDL2/SDL.h>

#include "InputManager.h"

InputManager::InputManager()
{
    SDL_InitSubSystem(SDL_INIT_EVENTS);
    for (int i = 0; i < SDL_NUM_SCANCODES; ++i)
    {
        keyStates[i] = false;
    }
    quit = false;
    
}

InputManager::~InputManager()
{
    SDL_QuitSubSystem(SDL_INIT_EVENTS);
}

void InputManager::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            keyStates[event.key.keysym.sym] = true;
            std::cout << event.key.keysym.sym << std::flush;
            break;
        case SDL_QUIT:
            quit = true;
            break;
        default:
            break;
        }
    }
}

bool InputManager::isKeyPressed(SDL_Keycode key)
{

    return keyStates[key];
}

bool InputManager::doQuit()
{
    return quit;
}
