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
	void Roll();
	void Evaluate();
	void HoldDice();
	void ShowDice();
	void DieValueCount(int *);
	void CalculateScore(int *);
	int GetMode(int *);

	Cup();
	Cup(bool);
};

#endif
