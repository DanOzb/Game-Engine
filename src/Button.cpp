#include "Button.h"
#include "GameEngine.h"

namespace engine{ 
    std::shared_ptr<Button> Button::make(float x, float y, float w, float h, std::string txt, Action doWhat){
        return ButtonPtr(new Button(x, y, w, h, txt, doWhat));
    }
    Button::Button(float x, float y, float w, float h, std::string txt, Action doWhat): Label(x, y, w, h, txt), doIt(doWhat){}

    void Button::draw() const{
        SDL_SetRenderDrawColor(eng.getRenderer(), 255, 192, 203, 255);
        SDL_RenderFillRect(eng.getRenderer(), &getRect()); 
        Label::draw();
    }

    void Button::onMouseDown(const SDL_Event& event){
        SDL_FPoint point = {event.button.x, event.button.y};
        if(SDL_PointInRectFloat(&point, &getRect())){
            down = true; 
        }
    }

    void Button::onMouseUp(const SDL_Event& event){
        SDL_FPoint point = {event.button.x, event.button.y};
        if(down && SDL_PointInRectFloat(&point, &getRect())){
            doIt(getText());
        }
        down = false;
    }
}