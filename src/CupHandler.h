#ifndef CUPHANDLER_H
#define CUPHANDLER_H

#include <vector>
#include <cstdlib>

using std::rand;

class Cup;

class CupHandler{

public:
	int topScore_;
	int tempWinner_;
	int wins_;
	int losses_;
	bool playerWin_;
	
	std::vector<Cup> player_;

	void TakeTurn(Cup&, int);
	void TakeTurns(int);
	void Roll(std::vector<Cup>&);
	void InitPlayers(int);
	void CheckScores();
	void Roll(Cup&);
	void CheckWinner(int);
	void Reset();
	
	CupHandler();
	~CupHandler();
};

#endif