#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

SDL_Texture *ResourceManager::loadTexture(SDL_Renderer* renderer, const std::string &filePath)
{
    if(textureCache.find(filePath) != textureCache.end())
    {
        return textureCache[filePath];
    }

    SDL_Texture *texture = loadTextureFromFile(renderer, filePath);
    textureCache[filePath] = texture;
    return texture;
}

SDL_Texture *ResourceManager::loadTextureFromFile(SDL_Renderer* renderer, std::string const &filePath)
{
    SDL_Texture* texture = IMG_LoadTexture (renderer, filePath.c_str());
    return texture;
}
