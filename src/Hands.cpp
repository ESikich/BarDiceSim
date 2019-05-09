#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include "GameHandler.h"
#include "Player.h"
#include <iomanip>

using std::vector;
using std::cout;
using std::endl;
using std::atoi;

int InputCheck(int &argc){
	if(argc < 8 || argc > 8){
		cout << "	Incorrect number of arguments." << endl;
		cout << "	Usage - hand [shakes] [d1] [d2] [d3] [d4] [d5] [#of simulations]" << endl;
		cout << "	-1 indicates an unused die" << endl;
		return 1;
	}
}

int main(int argc, char **argv){
	InputCheck(argc);

	cout << std::setprecision(2) << std::fixed;

	srand(time(NULL));
	int scores[57] = {0};
	int hand[5] = {-1};
	int numPlayers = 2;
	int numRolls = 3;
	int numRounds = 1000000;
	int topScore = 56;
	int scoreTotal = 0;

	vector<Player> player;
	GameHandler game = GameHandler();

	numRolls = atoi(argv[1]);
	hand[0] = atoi(argv[2]);
	hand[1] = atoi(argv[3]);
	hand[2] = atoi(argv[4]);
	hand[3] = atoi(argv[5]);
	hand[4] = atoi(argv[6]);
	numRounds = atoi(argv[7]);

	player.push_back(Player());

	for(int d = 0; d < 5; ++d){
		player[0].cup_.dice_[d].SetValue(hand[d]);
		if(hand[d] > 0){
			player[0].cup_.dice_[d].Hold();
		}
		if(hand[d] > 1){
			player[0].goal_ = hand[d];
		}
	}

	game.InitPlayers(player);

	for (int rounds = 0; rounds < numRounds; ++rounds) {
		game.TakeTurns(numRolls);
		++scores[player[0].score_];
		scoreTotal += player[0].score_;
		game.Reset();
		for(int d = 0; d < 5; ++d){
			player[0].cup_.dice_[d].SetValue(hand[d]);
			if(hand[d] > 0){
				player[0].cup_.dice_[d].Hold();
			}
			if(hand[d] > 1){
				player[0].goal_ = hand[d];
			}
		}
	}

	for(int i = 56; i > -1; --i){
		if(scores[i] > 0){
			float totScore = 0;
			cout << i << "\t" << 
			scores[i] << "\t" << 
			(scores[i]/(float)numRounds) * 100 << "%" << "\t";
			for(int x = i; x < 57; ++x){
				totScore += (scores[x]/(float)numRounds) * 100;
			}
			cout << totScore << "%" << endl;
		}
	}

	cout << endl << "Avg. hand - " << scoreTotal/(float)numRounds << endl;

	cout << "Complete." << endl;
	return 0;
}
