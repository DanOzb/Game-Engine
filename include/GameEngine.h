#pragma once

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>
#include "Sprite.h"

/**
 * Main engine class meant to track components and
 * handle sdl iniitialization + window
 */

namespace engine{
    typedef std::shared_ptr<Sprite> SpritePtr; 


    class GameEngine{
        public: 
            GameEngine(); 
            ~GameEngine(); 
            SDL_Renderer* getRenderer() const {return ren; }; 
            TTF_Font* getFont() const {return font; }
            void add(SpritePtr ptr);
            void run(); 
            bool checkCollision(const Sprite& a, const Sprite& b){
                return SDL_HasRectIntersectionFloat(&a.getRect(), &b.getRect());
            }
        private: 
            SDL_Window* win; 
            SDL_Renderer* ren; 
            TTF_Font* font; 
            std::vector<SpritePtr> components; 
    };

    extern GameEngine eng; 
}

