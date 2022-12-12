#include "Puzzle8.h"

using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;


Puzzle8::Puzzle8(std::string file){
	std::ifstream data;
	string line;

	data.open(file, std::ios::in);

	int row{0};

	if(data.fail()){
		cout << "Error: Failed to open file" << endl;
	}
	else {
		while(!data.eof()){
			getline(data, line);

			for(size_t i{0}; i < line.size(); ++i){
				forest[row][i].height = line[i];
			}

			++row;

		}
	}
}

void Puzzle8::evaluateForest(){

	// "All of the trees around the edge of the grid are visible - since they are 
	// already on the edge, there are no trees to block the view."

	for(int i{0}; i < 99; ++i){
		forest[0][i].visible = 1;
		forest[98][i].visible = 1;
		forest[i][0].visible = 1;
		forest[i][98].visible = 1;
	}

	look("down");
	look("up");
	look("right");
	look("left");

	int highestScore = 0;

	int visibilityCount{0};
	for(size_t i{0}; i < 99; ++i){
		for(size_t j{0}; j < 99; ++j){

			// Only calculate scores for the interior trees - edge trees always have a score of 0:
			// "(If a tree is right on the edge, at least one of its viewing distances will be zero.)"
			if(i > 0 && j > 0){
				calculateScenicScore(i, j);
			}

			if(forest[i][j].visible){
				++visibilityCount;
			}

			if(forest[i][j].scenicScore > highestScore){
				highestScore = forest[i][j].scenicScore;
			}
		}
	}

	cout << "Visibility Count: " << visibilityCount << endl;
	cout << "Highest Scenic Score: " << highestScore << endl << endl;
}


void Puzzle8::look(const std::string& direction){

	int tallestTree[98];

	if(direction == "down"){
		for(size_t i{1}; i < 98; ++i){
			tallestTree[i] = forest[0][i].height;
		}

		for(size_t i{1}; i < 98; ++i){
			for(size_t j{1}; j < 98; ++j){
				if(forest[i][j].height > tallestTree[j]){
					forest[i][j].visible = 1;
					tallestTree[j] = forest[i][j].height;
				}
			}
		}
	}

	if(direction == "up"){
		for(size_t i{1}; i < 98; ++i){
			tallestTree[i] = forest[98][i].height;
		}

		for(size_t i{97}; i > 0; --i){
			for(size_t j{1}; j < 98; ++j){
				if(forest[i][j].height > tallestTree[j]){
					forest[i][j].visible = 1;
					tallestTree[j] = forest[i][j].height;
				}
			}
		}
	}

	if(direction == "right"){
		for(size_t i{1}; i < 98; ++i){
			tallestTree[i] = forest[i][0].height;
		}

		for(size_t i{1}; i < 98; ++i){
			for(size_t j{1}; j < 98; ++j){
				if(forest[j][i].height > tallestTree[j]){
					forest[j][i].visible = 1;
					tallestTree[j] = forest[j][i].height;
				}
			}
		}
	}

	if(direction == "left"){
		for(size_t i{1}; i < 98; ++i){
			tallestTree[i] = forest[i][98].height;
		}

		for(size_t i{97}; i > 0; --i){
			for(size_t j{1}; j < 98; ++j){
				if(forest[j][i].height > tallestTree[j]){
					forest[j][i].visible = 1;
					tallestTree[j] = forest[j][i].height;
				}
			}
		}
	}

}

void Puzzle8::calculateScenicScore(const size_t y, const size_t x){

	int totalScenicScore{1};
	int directionalScore{1};

	// down
	for(size_t i{y + 1}; i < 98; ++i){
		if(forest[y][x].height <= forest[i][x].height){
			break;
		}
		++directionalScore;
	}

	
	totalScenicScore *= directionalScore;
	directionalScore = 1;


	// up
	for(size_t i{y - 1}; i > 0; --i){
		if(forest[y][x].height <= forest[i][x].height){
			break;
		}

		++directionalScore;
	}

	totalScenicScore *= directionalScore;
	directionalScore = 1;

	// right
	for(size_t i{x + 1}; i < 98; ++i){
		if(forest[y][x].height <= forest[y][i].height){
			break;
		}

		++directionalScore;
	}

	totalScenicScore *= directionalScore;
	directionalScore = 1;

	// left
	for(size_t i{x - 1}; i > 0; --i){
		if(forest[y][x].height <= forest[y][i].height){
			break;
		}

		++directionalScore;
	}

	totalScenicScore *= directionalScore;


	forest[y][x].scenicScore = totalScenicScore;

}


void Puzzle8::displayForest(){
	for(int i{0}; i < 99; ++i){
		for(int j{0}; j < 99; ++j){
			cout << forest[i][j].visible;
		}
		cout << endl;
	}
}