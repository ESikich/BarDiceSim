#ifndef CUP_H
#define CUP_H

#include "Die.h"

class Cup
{

public:
	bool farming_;
	int goal_;
	int score_;
	Die dice_[5] ={Die(), Die(), Die(), Die(), Die()};

	void Reset();
	void Shake();
	void ShowDice();

	Cup();
	Cup(bool);
};

#endif
