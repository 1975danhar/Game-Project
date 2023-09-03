#include "GameObject.h"

GameObject::GameObject(SDL_Renderer *renderer, ResourceManager &rm)
{
    this->renderer = renderer;
    resourceManager = rm;
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
