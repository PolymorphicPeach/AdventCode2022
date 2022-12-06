#include "SignalDecoder.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::set;

SignalDecoder::SignalDecoder(std::string fileName){

	std::ifstream data;

	data.open(fileName, std::ios::in);

	if(data.fail()){
		cout << "Error: " << fileName << " not found." << endl;
	}
	else{
		file = fileName;
	}

	data.close();
}

void SignalDecoder::populateDataString(){
	std::ifstream data;
	data.open(file, std::ios::in);

	string line;

	if(data.fail()){
		cout << "Error: " << file << " not found." << endl;
	}
	else{
		while(!data.eof()){
			getline(data, line);
			dataString += line;
		}
	}

	data.close();
}

int SignalDecoder::getMessageStartingIndex(int bufferSize){
	buffer = &dataString[0];
	int startingIndex{-1};
	int currentIndex{0};

	for(size_t i{0}; i < bufferSize; ++i){
		buffer[i] = dataString[i];
	}

	bool signalFound = false;

	while(!signalFound){
		set<char> chars;

		for(int i{0}; i < bufferSize; ++i){
			cout << *(buffer + i) << " ";
			chars.insert(*(buffer + i));
		}
		cout << endl;

		if(chars.size() == bufferSize){
			startingIndex = currentIndex + bufferSize - 1;
			signalFound = true;
		}

		++buffer;

		++currentIndex;
	}

	buffer = nullptr;

	return startingIndex;
}
