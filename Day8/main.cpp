#include <istream>
#include <chrono>
#include <string>
#include "Puzzle8.h"

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main(){

	auto startTime = std::chrono::high_resolution_clock::now();

	Puzzle8 puzzle("aoc8.txt");
	puzzle.evaluateForest();

	auto finishTime = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration < double >> (finishTime - startTime);

	cout << "Finished in: " << duration.count() << " seconds." << endl << endl;


	string quit;
	cout << "Enter any key to exit...";
	getline(cin, quit);
	cout << endl << endl;

	return 0;
}