#include "GameEngine.h"
#include "Button.h"
#include <memory>
#include <iostream>

/**
 * Main class. 
 * Used to test Button component now. 
 * Change Later 
 */

using namespace engine;
using namespace std;

void func(string txt){
	cout << txt << endl;
}

int main() {
	CompPtr c1 = Button::make(100, 100, 200, 75, "example 1", func);
	CompPtr c2 = Button::make(400, 100, 200, 75, "example 2", func);

	eng.add(c1); 
	eng.add(c2); 

	eng.run();
	return 0; 
}