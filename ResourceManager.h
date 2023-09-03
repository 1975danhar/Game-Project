#ifndef _RESOURCEMANAGER_
#define _RESOURCEMANAGER_

#include <iostream>
#include <unordered_map>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class ResourceManager
{
    public:
    ResourceManager();
    ~ResourceManager();
    SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& filePath);
    SDL_Texture* loadTextureFromFile(SDL_Renderer* renderer, const std::string& filePath);

    private:

    std::unordered_map<std::string, SDL_Texture *> textureCache;
};

#endif