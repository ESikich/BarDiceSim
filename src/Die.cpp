#include "Die.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

bool Die::IsHeld() const{
	return is_held_;
}

int Die::Value() const{
	return value_;
}

void Die::SetValue(int v){
	value_ = v;
}

void Die::Roll(){
	if (is_held_ == false){
		value_ = std::rand() % 6 + 1;
	}
}

void Die::Hold(){
	is_held_ = true;
}

void Die::Init(){
	is_held_ = false;
	value_ = -1;
}

void Die::Reset(){
	value_ = -1;
	is_held_ = false;
}

Die::Die(){
	Init();
}

Die::~Die(){

}
