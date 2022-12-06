#pragma once

#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

class Puzzle5{
private:
	std::vector<std::stack<char>> stacks;

public:
	Puzzle5();
	void populateStacks();
	void displayStacksTop();
	void moveCrates();
};

