#include "Die.h"
#include <cstdlib>

void Die::Roll(){
	if (holding_ == false){
		value_ = std::rand() % 6 + 1;
	}
}

void Die::Reset(){
	value_ = 0;
	holding_ = false;
}

bool Die::Held(){
	return holding_;
}

void Die::Hold(){
	holding_ = true;
}

int Die::Value(){
	return value_;
}

Die::Die(){
	Reset();
}

Die::~Die(){

}
