#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Device.h"

using namespace std;

int main(){
	std::ifstream data;
	string line;
	vector<string> input;

	data.open("aoc10.txt", std::ios::in);

	if(data.fail()){
		cout << "Error: Failed to open file." << endl;
	}
	else{
		while(!data.eof()){
			getline(data, line);
			input.push_back(line);
		}
	}

	Device device(input);
	device.readInstructions();
	device.drawImage();

	return 0;
}