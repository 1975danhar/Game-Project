#include "Ball.h"

Ball::Ball(SDL_Renderer *renderer, ResourceManager &rm): GameObject(renderer,  rm)
{
    this->renderer = renderer;
    ballTexture = rm.loadTextureFromFile(renderer, "Ball.png");
}

Ball::~Ball()
{

}

void Ball::update()
{
}

void Ball::render()
{
}
