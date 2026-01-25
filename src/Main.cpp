#include "GameEngine.h"
#include "Button.h"
#include "Label.h"
#include "Figure.h"
#include <memory>
#include <iostream>
#include <random>

/**
 * Main class. 
 * example game
 */

using namespace engine;
using namespace std;

float x_hero,y_hero = 0; 
SpritePtr enemyPtr = nullptr; 

class Enemy : public Figure {
public:
    Enemy(std::string sprite, float x, float y):Figure(sprite, x, y){}
	void tick(){
		if(getRect().x > x_hero){
			setRectPosition(getRect().x - 1, getRect().y);
		} else if(getRect().x < x_hero){
			setRectPosition(getRect().x + 1, getRect().y);
		}

		if(getRect().y > y_hero){
			setRectPosition(getRect().x, getRect().y - 1);
		} else if(getRect().y < y_hero){
			setRectPosition(getRect().x, getRect().y + 1);
		}
	}
};

class Point : public Figure {
public:

    Point(std::string sprite, float x, float y):Figure(sprite, x, y){}

};

class Player : public Figure {
public:

	float x_direction, y_direction = 0; 

    Player():Figure("PacmanSprites/Pacman/eatRight.png", 100, 100){
		x_hero = 10; 
		y_hero = 0; 
	}
	void onKeyDown(const SDL_Event& event) override {
        if (event.key.key == SDLK_W || event.key.key == SDLK_UP) {
            y_direction = -1; 
			x_direction = 0; 
        } else if(event.key.key == SDLK_S || event.key.key == SDLK_DOWN){
			y_direction = 1; 
			x_direction = 0; 
		}
		else if(event.key.key == SDLK_A || event.key.key == SDLK_LEFT){
			x_direction  = -1; 
			y_direction = 0; 
		}
		else if(event.key.key == SDLK_D || event.key.key == SDLK_RIGHT){
			x_direction  = 1; 
			y_direction = 0; 
		}

		x_hero = getRect().x; 
		y_hero = getRect().y; 
    }

	void tick(){
		if(eng.borderCollision(*this)){
			x_direction *= -1;
			y_direction *= -1; 
		}
		setRectPosition(getRect().x + x_direction, getRect().y + y_direction);
	}

};


int main() {
	auto hero = SpritePtr(new Player());
	enemyPtr = SpritePtr(new Enemy("PacmanSprites/Enemies/cyanGhost.png", 0, 0));
	

	eng.add(hero); 
	eng.add(enemyPtr);

	eng.run();
	return 0; 
}