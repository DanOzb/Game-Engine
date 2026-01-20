#include "GameEngine.h"
#include "Label.h"
#include <memory>

/**
 * Main class. 
 * Used to test components now. 
 * Change Later 
 */

using namespace engine;
using namespace std;
int main() {
	CompPtr c1 = Label::make(100, 100, 200, 75, "example 1");
	CompPtr c2 = Label::make(400, 100, 200, 75, "example 2");

	eng.add(c1); 
	eng.add(c2); 

	eng.run();
	return 0; 
}