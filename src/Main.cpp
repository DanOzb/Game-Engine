#include "GameEngine.h"
#include "Button.h"
#include "Label.h"
#include <memory>
#include <iostream>

/**
 * Main class. 
 * Used to implement a simple counter now.
 * Change Later 
 */

using namespace engine;
using namespace std;

LabelPtr label; 
int value = 0; 
void func(string txt){
	if(txt == "+")
		++value; 
	else 
		--value;
	label->setText(to_string(value));
}

int main() {
	CompPtr c1 = Button::make(100, 100, 100, 75, "+", func);
	CompPtr c2 = Button::make(400, 100, 100, 75, "-", func);
	label = Label::make(250, 100, 100, 75, "0");

	eng.add(c1); 
	eng.add(c2); 
	eng.add(label);

	eng.run();
	return 0; 
}