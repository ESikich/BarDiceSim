#ifndef PLAYER_H
#define PLAYER_H

#include "Cup.h"

class Player{
public:
	Cup cup_;
	bool farming_;
	int goal_;
	int score_;
	int wins_;
	int losses_;

	void Evaluate();
	void HoldDice();
	void DieValueCount(int *);
	void CalculateScore(int *);
	int GetMode(int *);
	void Reset();
	
	Player();
	~Player();
};

#endif
