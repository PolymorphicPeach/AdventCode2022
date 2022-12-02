#include "ElfExpedition.h"

using std::cout;
using std::cin;
using std::string;

ElfExpedition::ElfExpedition(){

	data.open("adventCode1.txt", std::ios::in);

	if(data.fail()){
		std::cerr << "Error: File not found \n";
	}
	else{
		data.close();
	}
}

void ElfExpedition::populateInventories(){
	data.open("adventCode1.txt", std::ios::in);

	string line;
	int totalCalories{0};

	while(!data.eof()){
		getline(data, line);

		if(!line.empty()){
			totalCalories += std::stoi(line);
		}
		else{
			elfInventories.push_back(totalCalories);
			totalCalories = 0;
		}
	}
}

int ElfExpedition::getElfWithMostCalories(){
	int mostCalories{0};

	for(int calories : elfInventories){
		if(calories > mostCalories){
			mostCalories = calories;
		}
	}

	return mostCalories;
}

int ElfExpedition::getTop3ElvesTotal(){

	int calories{0};

	std::sort(elfInventories.begin(), elfInventories.end(), std::greater<int>());

	for(size_t i{0}; i < 3; ++i){
		calories += elfInventories[i];
	}

	return calories;
}
