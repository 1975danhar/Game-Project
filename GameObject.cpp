#include "GameObject.h"

GameObject::GameObject(SDL_Renderer *renderer, ResourceManager &resourceManager)
{
    this->renderer = renderer;
    this->resourceManager = resourceManager;
}

GameObject::~GameObject()
{
}

void GameObject::update()
{
}

void GameObject::render()
{
}
