#include <ChoccoEngine/renderer.h>

namespace chocco {
// constructors and destructors
    Renderer::Renderer() : renderer(nullptr), flags(NULL) { }

    Renderer::Renderer(SDL_Window* window, int flags) : flags(flags) {
        renderer = SDL_CreateRenderer(window, -1, this->flags);
#ifndef ndebug
		if (renderer == nullptr) {
			SDLError("SDL create renderer error");
		}
#endif
    }

    void Renderer::destroy() {
        SDL_DestroyRenderer(renderer);
    }

// clear and present
    void Renderer::clear() {
        SDL_RenderClear(renderer);
    }

    void Renderer::present() {
        SDL_RenderPresent(renderer);
    }

    // primitive drawing
    void Renderer::drawPoint(Vector2 pos, SDL_Color color) {
        SDL_Color last;

        SDL_GetRenderDrawColor(renderer, &last.r, &last.g, &last.b, &last.a);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

#ifndef ndebug
        if (SDL_RenderDrawPointF(renderer, pos.x, pos.y) != 0) {
            SDLError("SDL renderer drawPoint error");
        }
#endif
#ifdef ndebug
        SDL_RenderDrawPointF(renderer, pos.x, pos.y)
#endif

        SDL_SetRenderDrawColor(renderer, last.r, last.g, last.b, last.a);
    }

    void Renderer::drawLine(Vector2 coord1, Vector2 coord2, SDL_Color color) {
        SDL_Color last;

        SDL_GetRenderDrawColor(renderer, &last.r, &last.g, &last.b, &last.a);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

#ifndef ndebug
        if (SDL_RenderDrawLineF(renderer, coord1.x, coord1.y, coord2.x, coord2.y) != 0) {
            SDLError("SDL renderer drawPoint error");
        }
#endif
#ifdef ndebug
        SDL_RenderDrawLineF(renderer, coord1.x, coord1.y, coord2.x, coord2.y)
#endif

        SDL_SetRenderDrawColor(renderer, last.r, last.g, last.b, last.a);
    }

    void Renderer::drawRect(SDL_FRect rect, SDL_Color color, bool filled) {
        SDL_Color last;

        SDL_GetRenderDrawColor(renderer, &last.r, &last.g, &last.b, &last.a);
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

#ifndef ndebug
        if (filled) {
            if (SDL_RenderDrawRectF(renderer, &rect) != 0) {
                SDLError("SDL renderer drawPoint error");
            }
        } else {
            if (SDL_RenderFillRectF(renderer, &rect) != 0) {
                SDLError("SDL renderer drawPoint error");
            }
        }
#endif
#ifdef ndebug
        if (filled) {
            SDL_RenderDrawRectF(renderer, &rect) != 0
        } else {
            SDL_RenderFillRectF(renderer, &rect)
        }
#endif
        
        SDL_SetRenderDrawColor(renderer, last.r, last.g, last.b, last.a);
    }

// sprite drawing
    void Renderer::drawSprite(Sprite sprite) {
        SDL_FRect dst = {sprite.getPosition().x * sprite.getScale().x, sprite.getPosition().y * sprite.getScale().y, sprite.getWidth(), sprite.getHeight()};
#ifndef ndebug
        if (SDL_RenderCopyExF(renderer, sprite.getTexture(), sprite.getClip(), &dst, sprite.getRotation(), &sprite.getRotationCenter(), SDL_FLIP_NONE) != 0) SDLError("SDL draw texture (sprite) error");
#endif
#ifdef ndebug
        SDL_RenderCopyExF(renderer, sprite.getTexture(), sprite.getClip(), &dst, sprite.getRotation(), &sprite.getRotationCenter(), SDL_FLIP_NONE)
#endif

    }

    void Renderer::drawSpriteGroup(SpriteGroup spriteGroup) {
        for (std::pair<std::string, Sprite> pair : spriteGroup.group) {
			drawSprite(pair.second);
		} 
    }

// tilemap drawing
    void Renderer::drawTilemap(Tilemap tilemap) {
        SDL_FRect dst = {0, 0, tilemap.getSize().x * tilemap.getClipSize(), tilemap.getSize().y * tilemap.getClipSize()};
#ifndef ndebug
        if (SDL_RenderCopyF(renderer, tilemap.getTexture(), NULL, &dst) != 0) SDLError("SDL draw texture (sprite) error");
#endif
#ifdef ndebug
        SDL_RenderCopyF(renderer, tilemap.getTexture(), tilemap.getClip(), &dst)
#endif

    }

    void Renderer::drawTileGroup(TileGroup group) {
        for (std::pair<std::string, Tilemap> pair : group.group) {
			drawTilemap(pair.second);
		} 
    }
}
