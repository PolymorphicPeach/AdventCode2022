#include <iostream>

#include "RPS.h"

int main(){
	RPS rps;

	rps.playGame();
	rps.displayScores();
	rps.resetScores();
	rps.playGamePt2();
	rps.displayScores();

	return 0;
}