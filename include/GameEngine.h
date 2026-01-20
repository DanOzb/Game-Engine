#pragma once

#include <vector>
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <memory>
#include "Component.h"

/**
 * Main engine header meant to track components and
 * handle sdl iniitialization + window
 */

namespace engine{
    typedef std::shared_ptr<Component> CompPtr; 


    class GameEngine{
        public: 
            GameEngine(); 
            ~GameEngine(); 
            SDL_Renderer* getRenderer() const {return ren; }; 
            TTF_Font* getFont() const {return font; }
            void add(CompPtr ptr);
            void run(); 

        private: 
            SDL_Window* win; 
            SDL_Renderer* ren; 
            TTF_Font* font; 
            std::vector<CompPtr> components; 
    };

    extern GameEngine eng; 
}

