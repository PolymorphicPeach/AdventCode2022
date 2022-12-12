#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <thread>


struct Tree{
	//int height{0};
	unsigned height : 4;

	// 1 = visible
	// 0 = invisible
	unsigned visible : 1;

	// In part 2:
	int scenicScore = 0;
};

class Puzzle8{
private:
	std::array<std::array<Tree, 99>, 99> forest;

	std::vector<std::string > forestStr;
	void look(const std::string& direction);
	void calculateScenicScore(const size_t y, const size_t x);

public:
	Puzzle8(std::string file);
	void evaluateForest();
	void displayForest();

};

