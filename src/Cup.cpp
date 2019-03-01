#include "Cup.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

void Cup::Roll() {
	for (int d = 0; d < 5; d++) {
		dice_[d].Roll();
	}
}

void Cup::DieValueCount(int * dvc) {
	for (int i = 0; i < 5; i++) {
		dvc[dice_[i].Value()]++;
	}
}

int Cup::GetMode(int * dvc) {
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

void Cup::CalculateScore(int * dvc) {
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

void Cup::Evaluate() {
	int diceCount[7] = {0, 0, 0, 0, 0, 0, 0};

	for (int i = 0; i < 5; i++) {
		diceCount[dice_[i].Value()]++;
	}

	if (diceCount[1] > 0) {
		CalculateScore(diceCount);
	}
}

void Cup::HoldDice() {
	if (farming_ == true) {
		for (int i = 0; i < 5; i++) {
			if (dice_[i].Value() == 1 || dice_[i].Value() == goal_) {
				dice_[i].Hold();
			}
		}
	}else {
		for (int i = 0; i < 5; i++) {
			if (dice_[i].Value() == 1) {
				dice_[i].Hold();
			}
		}
	}
}

void Cup::ShowDice() {
	for (int i = 0; i < 5; i++) {
		cout << dice_[i].Value() << " ";
	}
	cout << endl;
}

void Cup::Reset() {
	goal_ = 0;
	score_ = 0;
	for (int i = 0; i < 5; i++) {
		dice_[i].Reset();
	}
}

Cup::Cup() {
	farming_ = false;
	Reset();
}

Cup::Cup(bool f) {
	farming_ = f;
	Reset();
}