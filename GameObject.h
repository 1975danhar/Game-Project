#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include <SDL2/SDL.h>
#include "ResourceManager.h"
class GameObject
{
    public:
        GameObject(SDL_Renderer* renderer, ResourceManager& rm);
        virtual ~GameObject();
        virtual void update();
        virtual void render();
    private:
        SDL_Renderer* renderer;
        ResourceManager resourceManager;
};

#endif