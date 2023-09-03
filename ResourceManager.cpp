#include "ResourceManager.h"

ResourceManager::ResourceManager(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

ResourceManager::~ResourceManager()
{
}

SDL_Texture *ResourceManager::loadTexture(const std::string &filePath)
{
    if(textureCache.find(filePath) != textureCache.end())
    {
        return textureCache[filePath];
    }

    SDL_Texture *texture = loadTextureFromFile(filePath);
    textureCache[filePath] = texture;
    return texture;
}

SDL_Texture *ResourceManager::loadTextureFromFile(std::string const &filePath)
{
    SDL_Texture* texture = IMG_LoadTexture (renderer, filePath.c_str());
    return texture;
}
