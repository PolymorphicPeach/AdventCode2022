#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

class ElfExpedition{
private:
	std::ifstream data;
	std::vector<int> elfInventories;


public:
	ElfExpedition();
	void populateInventories();
	int getElfWithMostCalories();
	int getTop3ElvesTotal();
};

