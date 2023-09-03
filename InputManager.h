#ifndef _INPUTMANAGER_
#define _INPUTMANAGER_

#include <iostream>
#include <SDL2/SDL.h>

class InputManager
{
public:
    InputManager();
    ~InputManager();

    void poll();
    bool isKeyPressed(SDL_Keycode key);
    bool doQuit();

private:
    bool keyStates[SDL_NUM_SCANCODES];
    bool quit;
};

#endif