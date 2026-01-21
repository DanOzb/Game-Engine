#include "Figure.h"
#include "GameEngine.h"
#include <string>
#include <SDL3_image/SDL_image.h>
#include "Constants.h"
#include <iostream>

using namespace std;

namespace engine {

    FigurePtr Figure::make(std::string sprite_name, float x, float y){
        return FigurePtr(new Figure(sprite_name, x, y));
    }

    Figure::Figure(std::string sprite_name, float x, float y): Sprite(x, y){
        image = IMG_LoadTexture(eng.getRenderer(), (constants::gResPath + "/images/" + sprite_name).c_str()); 
        if(!image){
            cerr << "No such file" << sprite_name << endl; 
            exit(EXIT_FAILURE);
        } 
        float w = static_cast<float>(image->w); 
        float h = static_cast<float>(image->h); 
        setRectDimensions(w, h);
    }
    Figure::~Figure(){
        SDL_DestroyTexture(image); 
    }
    void Figure::draw() const{
        SDL_RenderTexture(eng.getRenderer(), image, NULL, &getRect());
    }

}