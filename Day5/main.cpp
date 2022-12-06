#include <iostream>

#include "Puzzle5.h"

using namespace std;

int main(){

	Puzzle5 puzzle;
	puzzle.populateStacks();
	puzzle.displayStacksTop();
	puzzle.moveCrates();
	puzzle.displayStacksTop();

	return 0;
}