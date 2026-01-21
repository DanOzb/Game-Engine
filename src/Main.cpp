#include "GameEngine.h"
#include "Button.h"
#include "Label.h"
#include "Figure.h"
#include <memory>
#include <iostream>

/**
 * Main class. 
 * Used to implement a simple counter now.
 * Change Later 
 */

using namespace engine;
using namespace std;

class StaticFigure : public Figure {
public:

    StaticFigure():Figure("example.png", 300, 0){}
};

class Player : public Figure {
public:

    Player():Figure("example.png", 10, 0){}
	void onKeyDown(const SDL_Event& event) override {
        if (event.key.key == SDLK_W || event.key.key == SDLK_UP) {
            setRectPosition(getRect().x, (getRect().y - 5));
            cout << "Hero moved up to: " << getRect().x << ", " << getRect().y << endl;
        } else if(event.key.key == SDLK_S || event.key.key == SDLK_DOWN){
			setRectPosition(getRect().x, (getRect().y + 5));
            cout << "Hero moved down to: " << getRect().x << ", " << getRect().y << endl;
		}
		else if(event.key.key == SDLK_A || event.key.key == SDLK_LEFT){
			setRectPosition(getRect().x - 5, getRect().y);
            cout << "Hero moved left to: " << getRect().x << ", " << getRect().y << endl;
		}
		else if(event.key.key == SDLK_D || event.key.key == SDLK_RIGHT){
			setRectPosition(getRect().x + 5, getRect().y);
            cout << "Hero moved right to: " << getRect().x << ", " << getRect().y << endl;
		}
    }
};


int main() {
	auto figure1 = SpritePtr(new StaticFigure()); 
	auto figure2 = SpritePtr(new Player());

	eng.add(figure1); 
	eng.add(figure2);

	eng.run();
	return 0; 
}