#include "Puzzle5.h"

using namespace std;

Puzzle5::Puzzle5(){
	std::ifstream data;
	data.open("aoc5.txt", std::ios::in);

	if(data.fail()){
		cout << "Error: File not found";
	}

	stacks.resize(9);

	data.close();
}

void Puzzle5::populateStacks(){
	std::ifstream data;
	data.open("aoc5.txt", std::ios::in);
	string line{"Unset"};
	bool finishedCrateReading{false};

	vector<stack<char>> intermediate;
	intermediate.resize(9);

	while(!data.eof() && !finishedCrateReading){
		getline(data, line);
		

		if(line[1] == '1'){
			finishedCrateReading = true;
		}

		if(!finishedCrateReading){
			for(size_t i{1}; i < line.size(); i += 4){
				if(i == 1 && !isspace(line[1])){
					intermediate[0].push(line[1]);
				}
				else{
					if(!isspace(line[i])){
						intermediate[(i / 4)].push(line[i]);
					}
				}
			}
		}
	}

	for(size_t i{0}; i < intermediate.size(); ++i){

		while(!intermediate[i].empty()){
			char crate = intermediate[i].top();
			intermediate[i].pop();
			stacks[i].push(crate);

		}

	}

	data.close();
}

void Puzzle5::displayStacksTop(){
	for(size_t i{0}; i < stacks.size(); ++i){
		if(!stacks[i].empty()){
			cout << stacks[i].top() << " ";
		}
		else{
			cout << "stack " << i << " is empty" << endl;
		}
	}

	cout << endl;
}

void Puzzle5::moveCrates(){
	std::ifstream data;
	data.open("aoc5.txt", std::ios::in);
	string line{"unset"};

	while(!data.eof()){
		getline(data, line);

		if(line[0] == 'm'){

			vector<string> words;

			istringstream inputString{line};
			string tempHolder;

			while(inputString >> tempHolder){
				words.push_back(tempHolder);
			}

			for(size_t i{0}; i < words.size(); ++i){
				if(!isdigit(words[i][0])){
					words.erase(words.begin() + i);
				}
			}

			int moveAmount = stoi(words[0]);
			int moveFrom = stoi(words[1]) - 1;
			int moveTo = stoi(words[2]) - 1;

			stack<char> intermediate;
			for(int i{0}; i < moveAmount; ++i){
				
				if(!stacks[moveFrom].empty()){
					//cout << "moving: " << i << endl;
					char crane = stacks[moveFrom].top();
					stacks[moveFrom].pop();
					intermediate.push(crane);


				}
			}

			while(!intermediate.empty()){
				char crate = intermediate.top();
				intermediate.pop();
				stacks[moveTo].push(crate);
			}


		}
	}
}
