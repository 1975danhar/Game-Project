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
    ResourceManager(SDL_Renderer* renderer);
    ~ResourceManager();
    SDL_Texture* loadTexture(const std::string& filePath);
    SDL_Texture* loadTextureFromFile(const std::string& filePath);

    private:
    SDL_Renderer* renderer;
    std::unordered_map<std::string, SDL_Texture *> textureCache;
};

#endif