#pragma once

#ifndef ndebug
#include <iostream>
#endif

#include <vector>
#include <fstream>
#include <SDL.h>
#include <noud.h>

#include <ChoccoEngine/Cmath.h>
#include <ChoccoEngine/loaders.h>

/**
 * Tilemaps
 * Tilemaps are just a sprite / a collection of sprites
 * If you want to make tilemaps, I would recomend you use this instead of normal sprites
 * This is a bit more efficient than to use the sprites
 * 
 * Has a function to load load the tile map folder (only .ctm files) and to create the tiles from it's base texture, which is loaded in the constructor
 * Also has a getter for the texture and the name
 **/

namespace chocco {
    class Tilemap : noud::Node {
    protected:
        SDL_Texture* baseTexture = nullptr, *texture = nullptr;
        std::vector <SDL_Rect> tiles;
        std::vector <std::vector <int>> tileData;

        int clipSize;
        Vector2 size = {0, 0};

        std::string loadFile(std::string path, int row);
    public:
        Tilemap();
        Tilemap(std::string name = "Tilemap");
        void destroy();

        void loadTileMap(std::string path, SDL_Renderer* renderer);
        void createTiles();

        std::string getName();
        SDL_Texture* getTexture();
        Vector2 getSize();
        int getClipSize();
    };
}
