#pragma once

#include <memory>
#include <SDL3/SDL.h>


/**
 * Component abstract base header meant for other 
 * engine components to inherit
 */

namespace engine {
    
    class Component{

        public: 
            virtual ~Component(){} 
            virtual void draw() const = 0; //abstract 
            const SDL_FRect& getRect() const {return rect; }

            Component(const Component& other) = delete;
            const Component& operator=(const Component& other) = delete;

        protected: 
            Component(float x, float y, float w, float h);

        private: 
            SDL_FRect rect; 
    };
    typedef std::shared_ptr<Component> CompPtr; 

}