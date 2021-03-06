#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <vector>
#include <cstdlib>
#include <iostream>
#include "Cup.h"
#include "Player.h"

using std::rand;
using std::vector;
using std::cout;
using std::endl;

class Cup;
class Player;

class GameHandler{

public:
	int topScore_;
	int tempWinner_;
	bool playerWin_;
	vector<Player>* player_;

	void TakeTurns(const int&);
	void InitPlayers(vector<Player>&);
	void CheckScores();
	void CheckWinner(const int&);
	void Reset();
	
	GameHandler();
	~GameHandler();
};

#endif
