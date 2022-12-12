#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>


struct knot{
	char* ptr;
	size_t x;
	size_t y;
};


class Day9{
private:
	std::vector<std::vector<char>> ropeGrid;
	std::vector<std::string> moves;

	char* head;
	size_t hX;
	size_t hY;

	char* tail;
	size_t tX;
	size_t tY;


	void move(bool moveX, bool posMove);
	void move2(knot* prevKnot, knot* knot, bool moveX, bool posMove);



public:
	Day9(std::string file);
	void part1();
	void part2(size_t ropeLen);

};

