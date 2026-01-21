#pragma once
#include "Sprite.h"
#include <string>
#include <memory>


/**
 * Label class for game gui
 */

namespace engine {
    class Label;
    typedef std::shared_ptr<Label> LabelPtr; 

    class Label : public Sprite{
        public: 
            static LabelPtr make(float x, float y, float w, float h, std::string txt); 
            void draw() const; 
            void setText(std::string newText);
            std::string getText() const {return text; }

            virtual ~Label();

        protected: 
            Label(float x, float y, float w, float h, std::string txt);
        private: 
            std::string text; 
            SDL_Texture* tex = nullptr;

    };
}