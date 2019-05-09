#include "Player.h"
#include <iostream>

using std::endl;
using std::cout;

int Player::GetMode(const int * dvc) const{
	int dieVal = 1;
	int tempCount = 0;

	for (int i = 2; i < 7; ++i) {
		if (dvc[i] >= tempCount && dvc[i] > 0) {
			tempCount = dvc[i];
			dieVal = i;
		}
	}

	return dieVal;
}

void Player::Evaluate() {
	int diceCount[7] = {0, 0, 0, 0, 0, 0, 0};

	for (int i = 0; i < 5; ++i) {
		++diceCount[cup_.dice_[i].Value()];
	}

	if (diceCount[1] > 0) {
		CalculateScore(diceCount);
	}
	
	if(diceCount[1] == 4){
		fourOnes_ = true;
	}
}

void Player::HoldDice() {
	if (farming_ == true) {
		for (int i = 0; i < 5; ++i) {
			if ((cup_.dice_[i].Value() == 1 && fourOnes_ == false) || cup_.dice_[i].Value() == goal_) {
				cup_.dice_[i].Hold();
			}
		}
	}else {
		for (int i = 0; i < 5; ++i) {
			if (cup_.dice_[i].Value() == 1) {
				cup_.dice_[i].Hold();
			}
		}
	}
}

void Player::CalculateScore(const int * dvc) {
	int dieVal = 0;
	int result = 0;

	dieVal = GetMode(dvc);

	if (goal_ == 0) {
		goal_ = dieVal;
	}

	result = (dvc[1] + dvc[goal_]) * 10 + goal_;
	if (result > 56 || dieVal == 0) {
		result = 0;
	}

	score_ = result;
}

void Player::Reset(){
	cup_ = Cup();
	farming_ = true;
	goal_ = 0;
	score_ = 0;
	fourOnes_ = false;
}

Player::Player(){
	Reset();
	wins_ = 0;
	losses_ = 0;
	farming_ = true;
	fourOnes_ = false;
}

Player::~Player(){

}
