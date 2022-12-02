#include "RPS.h"

using std::cout;
using std::cin;
using std::string;

RPS::RPS(){
	data.open("aoc2.txt", std::ios::in);

	if(data.fail()){
		std::cerr << "Error: File not found \n";
	}
	else{
		data.close();
	}

	myScore = 0;
	elfScore = 0;

}

void RPS::playGame(){
	data.open("aoc2.txt", std::ios::in);

	string line;
	string elfPlay;
	string myPlay;

	while(!data.eof()){
		getline(data, line);

		if(line[0] == 'A'){
			elfPlay = "rock";
			++elfScore;
		}
		if(line[0] == 'B'){
			elfPlay = "paper";
			elfScore += 2;
		}
		if(line[0] == 'C'){
			elfPlay = "scissors";
			elfScore += 3;
		}

		if(line[2] == 'X'){
			myPlay = "rock";
			++myScore;
		}
		if(line[2] == 'Y'){
			myPlay = "paper";
			myScore += 2;
		}
		if(line[2] == 'Z'){
			myPlay = "scissors";
			myScore += 3;
		}

		if(elfPlay == myPlay){
			elfScore += 3;
			myScore += 3;
		}
		
		if(elfPlay == "rock" && myPlay == "paper"){
			myScore += 6;

		}
		if(elfPlay == "rock" && myPlay == "scissors"){
			elfScore +=6;

		}
		if(elfPlay == "paper" && myPlay == "rock"){
			elfScore += 6;

		}
		if(elfPlay == "paper" && myPlay == "scissors"){
			myScore += 6;

		}
		if(elfPlay == "scissors" && myPlay == "rock"){
			myScore += 6;
		}
		if(elfPlay == "scissors" && myPlay == "paper"){
			elfScore += 6;

		}
	}

	data.close();
}

void RPS::displayScores(){
	cout << "My Score: " << myScore << "\n"
		<< "Elf Score: " << elfScore << "\n\n";
}

void RPS::resetScores(){
	myScore = 0;
	elfScore = 0;
}

void RPS::playGamePt2(){
	data.open("aoc2.txt", std::ios::in);

	string line;
	string elfPlay;
	string myPlay;

	while(!data.eof()){
		getline(data, line);

		if(line[0] == 'A'){
			elfPlay = "rock";
			++elfScore;

			if(line[2] == 'X'){
				myPlay = "scissors";
				myScore += 3;
			}
			if(line[2] == 'Y'){
				myPlay = elfPlay;
				++myScore;
			}
			if(line[2] == 'Z'){
				myPlay = "paper";
				myScore += 2;

			}


		}
		if(line[0] == 'B'){
			elfPlay = "paper";
			elfScore += 2;

			if(line[2] == 'X'){
				myPlay = "rock";
				++myScore;
			}
			if(line[2] == 'Y'){
				myPlay = elfPlay;
				myScore += 2;

			}
			if(line[2] == 'Z'){
				myPlay = "scissors";
				myScore += 3;
			}
		}
		if(line[0] == 'C'){
			elfPlay = "scissors";
			elfScore += 3;

			if(line[2] == 'X'){
				myPlay = "paper";
				myScore += 2;
			}
			if(line[2] == 'Y'){
				myPlay = elfPlay;
				myScore += 3;

			}
			if(line[2] == 'Z'){
				myPlay = "rock";
				++myScore;
			}

		}

		if(elfPlay == myPlay){
			elfScore += 3;
			myScore += 3;
		}

		if(elfPlay == "rock" && myPlay == "paper"){
			myScore += 6;

		}
		if(elfPlay == "rock" && myPlay == "scissors"){
			elfScore += 6;

		}
		if(elfPlay == "paper" && myPlay == "rock"){
			elfScore += 6;

		}
		if(elfPlay == "paper" && myPlay == "scissors"){
			myScore += 6;

		}
		if(elfPlay == "scissors" && myPlay == "rock"){
			myScore += 6;
		}
		if(elfPlay == "scissors" && myPlay == "paper"){
			elfScore += 6;

		}
	}

}
