#include "GameEngine.h"
#include "Button.h"
#include "Label.h"
#include "Figure.h"
#include <memory>
#include <iostream>
#include <random>
#include "Constants.h"

/**
 * Main class. 
 * example game
 */

using namespace engine;
using namespace std;

float x_hero,y_hero = 0; 
SpritePtr enemy = nullptr; 
SpritePtr hero = nullptr; 
int count_point = 0;
vector<SpritePtr> points = {};
LabelPtr score = nullptr; 
LabelPtr statusLabel = nullptr;

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

	void onCollision(Sprite& other) {
		if(Enemy* _ = dynamic_cast<Enemy*>(&other)){
			eng.remove(hero); 
			eng.setPaused(true); 
			statusLabel->setText("GAME OVER!");
		}
	}

};

class Point : public Figure {
public:
    Point(std::string sprite, float x, float y):Figure(sprite, x, y){}

	void onCollision(Sprite& other){
		if(Player* _ = dynamic_cast<Player*>(&other)){
			for(auto p : points){
				if(p.get()->getRect().x == getRect().x && p.get()->getRect().y == getRect().y){
					++count_point;
					eng.remove(p);
					break;
				}
			} 
			if(count_point == 10){
				eng.setPaused(true); 
				statusLabel->setText("YOU WON!");
			}
		}
	}

};

void func(){
	score.get()->setText(to_string(count_point));
}

int main() {
	hero = SpritePtr(new Player());
	enemy = SpritePtr(new Enemy("PacmanSprites/Enemies/cyanGhost.png", 0, 0));
	score = Label::make(300, 100, 50, 50, to_string(count_point)); 

	std::random_device rd;
    std::mt19937 gen(rd());

	std::uniform_real_distribution<float> distX(0, (float)constants::gScreenWidth - 20); 
    std::uniform_real_distribution<float> distY(0, (float)constants::gScreenHeight - 20);
	

	statusLabel = Label::make(300, 250, 200, 50, "");

	eng.add(hero); 
	eng.add(enemy);
	eng.add(score);
	eng.add(statusLabel);

	for (int i = 0; i < 10; ++i) {
        float randomX = distX(gen);
        float randomY = distY(gen);
        
        auto point = make_shared<Point>("PacmanSprites/Fruits/Apple.png", randomX, randomY); 
        eng.add(point);
		points.push_back(point);
    }

	eng.tick(func);

	eng.run();
	return 0; 
}