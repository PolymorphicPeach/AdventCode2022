#include <iostream>
#include <fstream>
#include<string>
#include <vector>

#include "Tree.h"

using namespace std;


int main(){
	Tree tree;
	tree.populateCommands("aoc7.txt");
	tree.readCommands();
	tree.populateDirSizes();
	tree.getSumDirectoryMem(100000);
	tree.part2();

	return 0;
}