#include "Player.h"

int Player::GetMode(int * dvc) const{
	int dieVal = 0;
	int tempCount = 0;

	for (int i = 2; i < 7; i++) {
		if (dvc[i] >= tempCount) {
			tempCount = dvc[i];
			dieVal = i;
		}
	}

	return dieVal;
}

void Player::Evaluate() {
	int diceCount[7] = {0, 0, 0, 0, 0, 0, 0};

	for (int i = 0; i < 5; i++) {
		diceCount[cup_.dice_[i].Value()]++;
	}

	if (diceCount[1] > 0) {
		CalculateScore(diceCount);
	}
}

void Player::HoldDice() {
	if (farming_ == true) {
		for (int i = 0; i < 5; i++) {
			if (cup_.dice_[i].Value() == 1 || cup_.dice_[i].Value() == goal_) {
				cup_.dice_[i].Hold();
			}
		}
	}else {
		for (int i = 0; i < 5; i++) {
			if (cup_.dice_[i].Value() == 1) {
				cup_.dice_[i].Hold();
			}
		}
	}
}

void Player::CalculateScore(int * dvc) {
	int dieVal = 0;
	int result = 0;

	dieVal = GetMode(dvc);

	if (goal_ == 0) {
		goal_ = dieVal;
	}

	result = (dvc[1] + dvc[dieVal]) * 10 + dieVal;
	
	if (result == 61) {
		score_ = 0;
	}

	score_ = result;
}

void Player::Reset(){
	cup_ = Cup();
	farming_ = false;
	goal_ = -1;
	score_ = 0;
}

Player::Player(){
	Reset();
	wins_ = 0;
	losses_ = 0;
}

Player::~Player(){

}