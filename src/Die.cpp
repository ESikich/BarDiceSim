#include "Die.h"
#include <cstdlib>

bool Die::Held() const{
	return holding_;
}

int Die::Value() const{
	return value_;
}

void Die::Roll(){
	if (holding_ == false){
		value_ = std::rand() % 6 + 1;
	}
}

void Die::Hold(){
	holding_ = true;
}

void Die::Init(){
	holding_ = false;
	value_ = -1;
}

void Die::Reset(){
	value_ = -1;
	holding_ = false;
}

Die::Die(){
	Init();
}

Die::~Die(){

}
