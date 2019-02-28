#include "die.h"
#include <cstdlib>

void Die::Roll() {
	if (holding_ == false) {
		value_ = std::rand() % 6 + 1;
	}
}

Die::Die(){
	value_ = 0;
	holding_ = false;
}


Die::~Die(){
}
