#include <iostream>
#include "SignalDecoder.h"

using std::cout;
using std::endl;

int main(){
	SignalDecoder decoder("aoc6.txt");
	decoder.populateDataString();

	cout << "Part 1 - Character: " << decoder.getMessageStartingIndex(4) + 1<< endl
		 << "Part 2 - Character: " << decoder.getMessageStartingIndex(14) + 1<< endl << endl;

	return 0;
}