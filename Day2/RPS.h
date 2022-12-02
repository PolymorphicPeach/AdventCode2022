#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>



class RPS{
private:
	std::ifstream data;
	int myScore;
	int elfScore;


public:
	RPS();
	void playGame();
	void displayScores();
	void resetScores();
	void playGamePt2();
};

