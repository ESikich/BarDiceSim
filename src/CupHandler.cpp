#include "CupHandler.h"

void CupHandler::TakeTurn(Cup& cup, int rolls) {
	for (int i = 0; i < rolls; i++) {
		Roll(cup);
	}
}

void CupHandler::TakeTurns(int rolls) {
	for (std::vector<Cup>::iterator it = player_.begin(); it != player_.end(); ++it) {
		for (int i = 0; i < rolls; i++) {
			it->Roll();
			it->Evaluate();
			it->HoldDice();
		}
	}
}

void CupHandler::InitPlayers(int numPlayers) {
	for (int i = 0; i < numPlayers; i++) {
		player_.push_back(Cup(true));
	}
}

void CupHandler::CheckScores() {
	for (int i = 0; i < player_.size(); i++) {
		if (player_[i].score_ >= topScore_) {
			tempWinner_ = i;
		}
	}
}

void CupHandler::CheckWinner(int t){
	topScore_ = t;
	if (tempWinner_ != -1) {
		if (player_[tempWinner_].score_ == topScore_) {
			if (rand() % 2 == 1) {
				playerWin_ = true;
			}
			else {
				playerWin_ = false;
			}
		}
		else {
			if (player_[tempWinner_].score_ > topScore_) {
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
		wins_++;
	}
	else {
		losses_++;
	}
}

void CupHandler::Reset(){
	playerWin_ = false;
	tempWinner_ = -1;
	for (std::vector<Cup>::iterator it = player_.begin(); it != player_.end(); ++it){
		it->Reset();
	}
}

void CupHandler::Roll(std::vector<Cup>& cup) {

}

void CupHandler::Roll(Cup& cup) {
	cup.Roll();
	cup.Evaluate();
	cup.HoldDice();
}

CupHandler::CupHandler(){
	topScore_ = 56;
	tempWinner_ = -1;
	wins_ = 0;
	losses_ = 0;
	playerWin_ = false;
}


CupHandler::~CupHandler()
{
}
