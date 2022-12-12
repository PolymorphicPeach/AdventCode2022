#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Device{
private:
	std::vector<std::string> instructions;
	
	size_t x;
	size_t cycle;
	int sumSignal;


	void add(int n);
	void add2(size_t n);
	void noop();
	void noop2();

	void drawPixel(size_t pos);
	void moveSprite();

	std::vector <char> crt;
	std::vector <char> sprite;

public:
	Device(std::vector<std::string> data) : instructions(data), x(1), sumSignal(0), cycle(1){
		crt.resize(40);
		sprite.resize(40);
		sprite[0] = '#';
		sprite[1] = '#';
		sprite[2] = '#';
	}

	void readInstructions();
	void drawImage();



};

