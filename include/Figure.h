#pragma once
#include "Sprite.h"
#include <string>
#include <memory>

/**
 * Figure class used to add image sprites
 */

namespace engine{
    class Figure; 
    typedef std::shared_ptr<Figure> FigurePtr;

    class Figure : public Sprite{
        public: 
            static FigurePtr make(std::string sprite_name, float x, float y); 
            void draw() const; 

            virtual ~Figure();

        protected: 
            Figure(std::string sprite_name, float x, float y);
        private: 
            SDL_Texture* image = nullptr;

    };

}