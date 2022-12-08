#pragma once

#include "Directory.h"
#include "File.h"

#include <fstream>
#include <iostream>
#include <string>

class Tree{
private:
	Node* root;
	Node* tNode;
	std::vector<std::string> commands;
	int memAcc;

	int ans1;
	int ans2;

	void executeCommand(size_t& commandIndex);
	void traversal(Node* traversalNode);
	void postOrderTraversal(Node* traversalNode, int max);
	
	void part2Helper(Node* traversalNode, int neededSpace);

public:
	Tree(){
		root = new Directory("root", 0);
		tNode = root;
		memAcc = 0;
		ans1 = 0;
		ans2 = 0;

	}

	void populateCommands(std::string file);
	void readCommands();
	void populateDirSizes();
	void getSumDirectoryMem(int max);
	void part2();
};

