#ifndef PLAYER_H
#define PLAYER_H

#include "Cup.h"

class Player{
	int GetMode(int *) const;
	
public:
	Cup cup_;
	bool farming_;
	int goal_;
	int score_;
	int wins_;
	int losses_;

	void Evaluate();
	void HoldDice();
	void CalculateScore(int *);
	void Reset();
	
	Player();
	~Player();
};

#endif
