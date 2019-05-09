#include "Cup.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;

void Cup::Shake(){
	for (int d = 0; d < 5; ++d) {
		dice_[d].Roll();
	}
}

void Cup::ShowDice() {
	for (int i = 0; i < 5; ++i) {
		cout << dice_[i].Value() << " ";
	}
	cout << endl;
}

void Cup::Reset() {
	for (int i = 0; i < 5; ++i) {
		dice_[i].Reset();
	}
}

Cup::Cup() {
	Reset();
}

Cup::Cup(bool f) {
	Reset();
}
