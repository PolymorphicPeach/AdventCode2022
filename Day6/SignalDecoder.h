#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <set>

class SignalDecoder{
private:
	std::string file;
	std::string dataString;
	char* buffer;

public:
	SignalDecoder(std::string fileName);
	void populateDataString();
	int getMessageStartingIndex(int bufferSize);

};

