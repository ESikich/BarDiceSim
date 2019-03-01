#include "GameHandler.h"

void GameHandler::TakeTurns(int rolls) {
	for (std::vector<Player>::iterator it = player_->begin(); it != player_->end(); ++it) {
		for (int i = 0; i < rolls; i++) {
			it->cup_.Shake();
			it->Evaluate();
			it->HoldDice();
		}
	}
}

void GameHandler::InitPlayers(vector<Player>* player) {
	player_ = player;
}

void GameHandler::CheckScores() {
	for (int i = 0; i < player_->size(); i++) {
		if (player_->at(i).score_ >= topScore_) {
			tempWinner_ = i;
		}
	}
}

void GameHandler::CheckWinner(int t){
	topScore_ = t;
	if (tempWinner_ != -1) {
		if (player_->at(tempWinner_).score_ == topScore_) {
			if (rand() % 2 == 1) {
				playerWin_ = true;
			}
			else {
				playerWin_ = false;
			}
		}
		else {
			if (player_->at(tempWinner_).score_ > topScore_) {
				playerWin_ = false;
			}
			else {
				playerWin_ = true;
			}
		}
	}
	else {
		playerWin_ = true;
	}

	if (playerWin_ == true) {
		player_->front().wins_++;
	}
	else {
		player_->front().losses_++;
	}
}

void GameHandler::Reset(){
	playerWin_ = false;
	tempWinner_ = -1;
	for (std::vector<Player>::iterator it = player_->begin(); it != player_->end(); ++it){
		it->Reset();
	}
}

GameHandler::GameHandler(){
	topScore_ = 56;
	tempWinner_ = -1;
	playerWin_ = false;
}


GameHandler::~GameHandler()
{
}
