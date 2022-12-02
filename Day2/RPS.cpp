#include "RPS.h"

using std::cout;
using std::cin;
using std::string;

RPS::RPS(){

	std::ifstream data;

	data.open("aoc2.txt", std::ios::in);

	if(data.fail()){
		std::cerr << "Error: File not found \n";
	}
	else{
		data.close();
	}
}

void RPS::playBothGames(){

	std::thread part1(&RPS::playPart1, this);
	std::thread part2(&RPS::playPart2, this);

	part1.join();
	part2.join();
}

void RPS::playPart1(){

	std::ifstream file;
	file.open("aoc2.txt", std::ios::in);

	string line;
	int elfScorePt1{0};
	int myScorePt1{0};

	while(!file.eof()){

		getline(file, line);

		int elfScoreForRound{0};
		int myScoreForRound{0};

		switch(line[0]){
		case 'C':
			++elfScoreForRound;

		case 'B':
			++elfScoreForRound;

		default:
			++elfScoreForRound;
		}

		switch(line[2]){
		case 'Z':
			++myScoreForRound;

		case 'Y':
			++myScoreForRound;

		default:
			++myScoreForRound;
		}

		switch(elfScoreForRound){

		case 1:

			switch(myScoreForRound){
			case 1:
				myScoreForRound += 3;
				elfScoreForRound += 3;
				break;

			case 2:
				myScoreForRound += 6;
				break;

			case 3:
				elfScoreForRound += 6;
				break;
			}
			break;

		case 2:

			switch(myScoreForRound){
			case 1:
				elfScoreForRound += 6;
				break;

			case 2:
				myScoreForRound += 3;
				elfScoreForRound += 3;
				break;

			case 3:
				myScoreForRound += 6;
				break;
			}
			break;

		case 3:

			switch(myScoreForRound){
			case 1:
				myScoreForRound += 6;
				break;

			case 2:
				elfScoreForRound += 6;
				break;

			case 3:
				myScoreForRound += 3;
				elfScoreForRound += 3;
				break;
			}
		}

		elfScorePt1 += elfScoreForRound;
		myScorePt1 += myScoreForRound;

	}

	cout << "My Score Pt1: " << myScorePt1 << "\n";
	cout << "Elf Score Pt1: " << elfScorePt1 << "\n\n";

	file.close();
}

void RPS::playPart2(){

	std::ifstream file;
	file.open("aoc2.txt", std::ios::in);

	string line;
	int elfScorePt2{0};
	int myScorePt2{0};

	while(!file.eof()){

		getline(file, line);

		int elfScoreForRound{0};
		int myScoreForRound{0};

		switch(line[0]){
		case 'A':
			++elfScoreForRound;

			switch(line[2]){
			case 'X':
				myScoreForRound += 3;
				break;

			case 'Y':
				++myScoreForRound;
				break;

			case 'Z':
				myScoreForRound += 2;
				break;

			}

			break;

		case 'B':
			elfScoreForRound += 2;

			switch(line[2]){

			case 'X':
				++myScoreForRound;
				break;

			case 'Y':
				myScoreForRound += 2;
				break;
				
			case 'Z':
				myScoreForRound += 3;
				break;
			}

			break;

		case 'C':
			elfScoreForRound += 3;

			switch(line[2]){

			case 'X':
				myScoreForRound += 2;
				break;

			case 'Y':
				myScoreForRound += 3;
				break;

			case 'Z':
				++myScoreForRound;
				break;
			}

			break;
		}

		elfScoreForRound += 6;

		switch(line[2]){
		case 'Z':
			myScoreForRound += 3;
			elfScoreForRound -= 3;

		case 'Y':
			myScoreForRound += 3;
			elfScoreForRound -= 3;
		}

		myScorePt2 += myScoreForRound;
		elfScorePt2 += elfScoreForRound;
	}

	cout << "My Score Pt2: " << myScorePt2 << "\n";
	cout << "Elf Score Pt2: " << elfScorePt2 << "\n\n";

	file.close();
}
