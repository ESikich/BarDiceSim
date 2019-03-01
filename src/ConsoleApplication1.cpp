#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "Cup.h"
#include "CupHandler.h"
#include "die.h"

using std::vector;
using std::cout;
using std::endl;
using std::atoi;

int main(int argc, char **argv){
	
	if(argc < 3){
		cout << "Incorrect number of arguments." << endl;
		cout << "Usage - dice [players] [score] [shakes]" << endl;
		return 1;
	}
	
	srand((unsigned int)time(NULL));
	
	int numPlayers = 2;
	int numRolls = 3;
	int numRounds = 100000;
	int topScore = 56;
	int scoreList[20] = {22, 23, 24, 25, 26, 32, 33, 34, 35, 36, 42, 43, 44, 45, 46, 52, 53, 54, 55, 56};
	CupHandler game = CupHandler();

	numPlayers = atoi(argv[1]);
	topScore = atoi(argv[2]);
	numRolls = atoi(argv[3]);
	game.InitPlayers(numPlayers);

	//	for (int h = 0; h < 20; h++) {
	//topScore = scoreList[h];
	for (int rounds = 0; rounds < numRounds; rounds++) {
		game.TakeTurns(numRolls);
		game.CheckScores();			
		game.CheckWinner(topScore);
		game.Reset();
	}

	cout << "Score - " << topScore << " in " << numRolls << endl;
	cout << "Wins - " << game.wins_ << "  Losses - " << game.losses_ << endl;
	float percentage = ((float)game.wins_ / numRounds) * 100;
	cout <<"Total - " << percentage << "%" << endl;
	game.wins_ = 0;
	game.losses_ = 0;
	//}

	cout << "Complete.";
	return 0;
}
