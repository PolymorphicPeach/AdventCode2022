#include "Device.h"

using namespace std;

void Device::readInstructions(){

	for(size_t i{0}; i < instructions.size(); ++i){

		if(instructions[i][0] == 'a'){
			add(stoi(instructions[i].substr(5)));
		}

		if(instructions[i][0] == 'n'){
			noop();
		}

	}

	cout << sumSignal << endl << endl;

}

void Device::drawImage(){

	x = 1;
	cycle = 0;

	size_t spritePosition = 1;

	for(size_t i{0}; i < instructions.size(); ++i){

		if(instructions[i][0] == 'a'){
			add2(stoi(instructions[i].substr(5)));
		}

		if(instructions[i][0] == 'n'){
			noop2();
		}

	}
}


void Device::add2(size_t n){

	size_t pos = (cycle % 40);
	++cycle;
	
	drawPixel(pos);

	pos = (cycle % 40);
	drawPixel(pos);
	++cycle;
	
	x += n;
	moveSprite();
}


void Device::noop2(){
	size_t pos = (cycle % 40);

	++cycle;

	drawPixel(pos);
}

void Device::drawPixel(size_t pos){
	if(sprite[pos] == '#'){
		crt[pos] = '#';
	}
	else{
		crt[pos] = '.';
	}

	if(pos == 39){
		for(auto c : crt){
			cout << c;
		}
		cout << endl;


		for(auto c : crt){
			c = '\0';
		}

	}
}

void Device::moveSprite(){
	for(size_t i{0}; i < sprite.size(); ++i){

		sprite[i] = '.';
		
		if(x - 1 == i){
			sprite[i] = '#';
		}
		if(x == i){
			sprite[i] = '#';
		}
		if(x + 1 == i){
			sprite[i] = '#';
		}
	}
}


void Device::add(int n){
	++cycle;

	if(cycle == 20){
		sumSignal += (x * 20);
	}

	if(cycle == 60){
		sumSignal += (x * 60);
	}

	if(cycle == 100){
		sumSignal += (x * 100);
	}

	if(cycle == 140){
		sumSignal += (x * 140);
	}

	if(cycle == 180){
		sumSignal += (x * 180);
	}

	if(cycle == 220){
		sumSignal += (x * 220);
	}

	++cycle;
	if(cycle == 20){
		sumSignal += (x * 20);
	}

	if(cycle == 60){
		sumSignal += (x * 60);
	}

	if(cycle == 100){
		sumSignal += (x * 100);
	}

	if(cycle == 140){
		sumSignal += (x * 140);
	}

	if(cycle == 180){
		sumSignal += (x * 180);
	}

	if(cycle == 220){
		sumSignal += (x * 220);
	}


	x += n;
}




void Device::noop(){
	++cycle;

	if(cycle == 20){
		sumSignal += (x * 20);
	}

	if(cycle == 60){
		sumSignal += (x * 60);
	}

	if(cycle == 100){
		sumSignal += (x * 100);
	}

	if(cycle == 140){
		sumSignal += (x * 140);
	}

	if(cycle == 180){
		sumSignal += (x * 180);
	}

	if(cycle == 220){
		sumSignal += (x * 220);	
	}
}