#pragma once

#include <memory>
#include <SDL3/SDL.h>


/**
 * Sprite abstract base class acting as node entity
 */

namespace engine {
    
    class Sprite{

        public: 
            virtual ~Sprite(){} 
            virtual void draw() const = 0; //abstract 
            const SDL_FRect& getRect() const {return rect; }
            virtual void onMouseDown(const SDL_Event& event){}
            virtual void onMouseUp(const SDL_Event& event){}
            virtual void onKeyDown(const SDL_Event& event){}
            virtual void onKeyUp(const SDL_Event& event){}
            virtual void onCollision(Sprite& other){}
            virtual void tick(){}

            //rect setters
            void setRectDimensions(float w, float h){rect.w = w, rect.h = h;}
            void setRectPosition(float x, float y){rect.x = x, rect.y = y;}

            Sprite(const Sprite& other) = delete;
            const Sprite& operator=(const Sprite& other) = delete;

        protected: 
            Sprite(float x, float y);

        private: 
            SDL_FRect rect; 
    };
    typedef std::shared_ptr<Sprite> SpritePtr; 

}