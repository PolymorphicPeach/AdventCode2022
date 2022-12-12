#include "Day9.h"

using namespace std;


Day9::Day9(std::string file){
	std::ifstream data;
	string line;

	data.open(file, std::ios::in);

	if(data.fail()){
		cout << "Error: Failed to open file." << endl;
	}

	int requiredX{1};
	int requiredY{1};

	while(!data.eof()){
		getline(data, line);

		moves.push_back(line);

		switch(line[0]){
		case 'U':
			requiredY += stoi(line.substr(2));
			break;

		case 'D':
			requiredY += stoi(line.substr(2));
			break;

		case 'R':
			requiredX += stoi(line.substr(2));
			break;

		case 'L':
			requiredX += stoi(line.substr(2));
			break;

		default:
			cout << "Error - Unable to read line: " << line << endl << endl;
		}
	}

	requiredY = abs(requiredY);

	size_t y = requiredY;
	size_t x = requiredX;


	ropeGrid.resize(y + 1, vector<char>(x + 1));

	hX = ropeGrid.size() / 2;
	hY = ropeGrid[hX].size() / 2;

	tX = ropeGrid.size() / 2;
	tY = ropeGrid[tX].size() / 2;


}

void Day9::part1(){

	head = &ropeGrid[hX][hY];
	tail = head;

	for(std::string line : moves){

		switch(line[0]){
		case 'U':

			for(size_t i {0}; i < (size_t) stoi(line.substr(2)); ++i){
				move(false, true);

			}

			break;

		case 'D':
			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){
				move(false, false);

			}

			break;

		case 'R':
			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){
				move(true, true);

			}
			break;

		case 'L':
			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){
				move(true, false);

			}
			break;

		default:
			cout << "Error: Unable to read line." << endl << endl;
		}
	}

	int count{0};

	for(size_t i{0}; i < ropeGrid.size(); ++i){
		for(size_t j{0}; j < ropeGrid[i].size(); ++j){
			if(ropeGrid[i][j] == '#'){
				++count;
			}
		}
	}

	cout << "Count = " << count << endl << endl;

}

void Day9::part2(size_t ropeLen){
	for(size_t i{0}; i < ropeGrid.size(); ++i){
		for(size_t j{0}; j < ropeGrid[i].size(); ++j){
			if(ropeGrid[i][j] != '\0'){
				ropeGrid[i][j] = '\0';
			}
		}
	}

	vector<knot*> rope;
	rope.resize(ropeLen);

	size_t midY = ropeGrid.size() / 2;
	size_t midX = ropeGrid[midY].size() / 2;

	for(size_t i{0}; i < rope.size(); ++i){
		rope[i] = new knot();

		rope[i]->ptr = &ropeGrid[midY][midX];
		rope[i]->x = midX;
		rope[i]->y = midY;
	}

	for(std::string line : moves){

		switch(line[0]){
		case 'U':

			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){

				rope[0]->y += 1;
				rope[0]->ptr = &ropeGrid[rope[0]->y][rope[0]->x];

				for(size_t j{1}; j < rope.size(); ++j){
					move2(rope[j-1], rope[j], false, true);
				}

				*(rope[rope.size() - 1]->ptr) = '#';
			}

			break;

		case 'D':

			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){

				rope[0]->y -= 1;
				rope[0]->ptr = &ropeGrid[rope[0]->y][rope[0]->x];


				for(size_t j{1}; j < rope.size(); ++j){
					move2(rope[j - 1], rope[j], false, false);
				}

				*(rope[rope.size() - 1]->ptr) = '#';
			}

			break;

		case 'R':

			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){

				rope[0]->x += 1;
				rope[0]->ptr = &ropeGrid[rope[0]->y][rope[0]->x];

				for(size_t j{1}; j < rope.size(); ++j){
					move2(rope[j - 1], rope[j], true, true);
				}

				*(rope[rope.size() - 1]->ptr) = '#';
			}

			break;

		case 'L':

			for(size_t i{0}; i < (size_t)stoi(line.substr(2)); ++i){

				rope[0]->x -= 1;
				rope[0]->ptr = &ropeGrid[rope[0]->y][rope[0]->x];

				for(size_t j{1}; j < rope.size(); ++j){
					move2(rope[j - 1], rope[j], true, false);
				}

				*(rope[rope.size() - 1]->ptr) = '#';
			}
			break;

		default:
			cout << "Error: Unable to read line." << endl << endl;
		}
	}


	int count{0};

	for(size_t i{0}; i < ropeGrid.size(); ++i){
		for(size_t j{0}; j < ropeGrid[i].size(); ++j){
			if(ropeGrid[i][j] == '#'){
				++count;
			}
		}
	}

	cout << "Count = " << count << endl << endl;
}

void Day9::move2(knot* prevKnot, knot* knot, bool moveX, bool posMove){
	if(!moveX && posMove){
		if(knot->y - prevKnot->y > 1){
			knot->y -= 1;

			if(prevKnot->x != knot->x){
				knot->x = prevKnot->x;
			}
		}
	}
	else if(!moveX && !posMove){
		if(prevKnot->y - knot->y > 1){
			knot->y += 1;

			if(prevKnot->x != knot->x){
				knot->x = prevKnot->x;
			}
		}
	}
	else if(moveX && posMove){
		if(prevKnot->x - knot->x > 1){
			knot->x += 1;

			if(prevKnot->y != knot->y){
				knot->y = prevKnot->y;
			}
		}
	}
	else if(moveX && !posMove){
		if(knot->x - prevKnot->x > 1){
			knot->x -= 1;

			if(prevKnot->y != knot->y){
				knot->y = prevKnot->y;
			}
		}
	}

	knot->ptr = &ropeGrid[knot->y][knot->x];
}

void Day9::move(bool moveX, bool posMove){
	if(!moveX && posMove){
		hY += 1;
		head = &ropeGrid[hX][hY];

		if(hY - tY > 1){
			tY += 1;

			if(hX != tX){
				tX = hX;
			}

			tail = &ropeGrid[tX][tY];
			*tail = '#';
		}
	}
	else if(!moveX && !posMove){
		hY -= 1;
		head = &ropeGrid[hX][hY];

		if(tY - hY > 1){
			tY -= 1;

			if(hX != tX){
				tX = hX;
			}
			tail = &ropeGrid[tX][tY];
			*tail = '#';
		}
	}
	else if(moveX && posMove){
		hX += 1;
		head = &ropeGrid[hX][hY];

		if(hX - tX > 1){
			tX += 1;

			if(hY != tY){
				tY = hY;
			}
		}
	}
	else if(moveX && !posMove){
		hX -= 1;
		head = &ropeGrid[hX][hY];

		if(tX - hX > 1){
			tX -= 1;

			if(hY != tY){
				tY = hY;
			}
		}
	}

	tail = &ropeGrid[tX][tY];
	*tail = '#';
}