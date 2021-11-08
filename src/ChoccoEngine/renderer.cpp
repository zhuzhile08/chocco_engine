#include "renderer.h"

/**
 * Renderer Class
 * It's basicly a simpler version of the SDL renderer, because I simplyfied a lot of stuff
 * It contains / still in progress /
**/


namespace ChoccoEngine {
    Renderer::Renderer() : renderer(nullptr), flags(NULL) { }

    Renderer::Renderer(SDL_Window* window, int flags) : flags(flags) {
        renderer = SDL_CreateRenderer(window, -1, this->flags);
#ifndef ndebug
		if (renderer == nullptr) {
			SDLError("SDL create renderer error");
		}
#endif
    }

    Renderer::~Renderer() {
        delete renderer;
    }

    void Renderer::clear() {
        SDL_RenderClear(renderer);
    }

    void Renderer::present() {
        SDL_RenderPresent(renderer);
    }

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
}
