#pragma once
#include "Component.h"
#include <string>
#include <memory>


/**
 * Example child component inherited from base Component class 
 */

namespace engine {
    class Label;
    typedef std::shared_ptr<Label> LabelPtr; 

    class Label : public Component{
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