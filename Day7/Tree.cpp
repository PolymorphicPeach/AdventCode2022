#include "Tree.h"

using namespace std;

void Tree::executeCommand(size_t& commandIndex){

	if(commands[commandIndex].substr(2, 5) == "cd .."){

		tNode = tNode->getParent();
	}
	else if(commands[commandIndex].substr(2, 2) == "cd"){

		size_t i{0};
		bool targetFound{false};
		while(tNode->getChild(i) && !targetFound){

			if(tNode->getChild(i)->getName() == commands[commandIndex].substr(5, commands[commandIndex].size() - 5)){

				tNode = tNode->getChild(i);

				targetFound = true;

				break;
			}

			++i;
		}

	}
	else if(commands[commandIndex].substr(2, 2) == "ls"){
		++commandIndex;

		bool nextCommandFound{false};

		while(!nextCommandFound){

			if(static_cast<unsigned char>  (isdigit(commands[commandIndex][0]))){

				size_t spaceIndex = commands[commandIndex].find(" ");
				int size = stoi(commands[commandIndex].substr(0, spaceIndex));

				tNode->addNode(commands[commandIndex].substr(spaceIndex + 1), size);

			}
			else{
				tNode->addNode(commands[commandIndex].substr(4, commands[commandIndex].size() - 4), 0);
			}


			if(commandIndex == commands.size() - 1 || commands[commandIndex + 1][0] == '$'){
				nextCommandFound = true;
			}
			else{
				++commandIndex;
			}


		}
	}


}

void Tree::traversal(Node* traversalNode){
	if(!traversalNode){
		return;
	}

	memAcc += traversalNode->getSize();


	if(traversalNode->getNumChildren() > 0){

		for(size_t i{0}; i < traversalNode->getNumChildren(); ++i){

			traversal(traversalNode->getChild(i));
			traversalNode->setSize(memAcc);
			memAcc = 0;

		}

		memAcc += traversalNode->getSize();
	}
}

void Tree::postOrderTraversal(Node* traversalNode, int max){
	if(!traversalNode){
		return;
	}

	if(traversalNode->getNumChildren() > 0){
		for(size_t i{0}; i < traversalNode->getNumChildren(); ++i){
			postOrderTraversal(traversalNode->getChild(i), max);
		}
	}

	if(traversalNode->getType() == "Dir" && traversalNode->getSize() <= max){
		ans1 += traversalNode->getSize();
	}
}

void Tree::part2Helper(Node* traversalNode, int neededSpace){
	if(!traversalNode){
		return;
	}

	if(traversalNode->getNumChildren() > 0){
		for(size_t i{0}; i < traversalNode->getNumChildren(); ++i){
			part2Helper(traversalNode->getChild(i), neededSpace);
		}
	}

	if(traversalNode->getType() == "Dir" && traversalNode->getSize() >= neededSpace){
		if(traversalNode->getSize() < ans2){
			ans2 = traversalNode->getSize();
		}
	}

}

void Tree::populateCommands(std::string file){
	std::ifstream data;
	string line;

	data.open(file, std::ios::in);

	if(data.fail()){
		cout << "Error: file not found." << endl;
	}

	while(!data.eof()){
		getline(data, line);

		commands.push_back(line);
	}

	data.close();
}

void Tree::readCommands(){

	tNode = root;

	for(size_t i{1}; i < commands.size(); ++i){

		if(commands[i][0] == '$'){

			executeCommand(i);
		}
	}

	tNode = root;
}

void Tree::populateDirSizes(){
	tNode = root;
	memAcc = 0;

	traversal(tNode);
}

void Tree::getSumDirectoryMem(int max){

	tNode = root;
	

	postOrderTraversal(tNode, max);
	cout << endl << ans1 << endl << endl;

	tNode = root;
}

void Tree::part2(){
	tNode = root;
	ans2 = tNode->getSize();

	int unusedSpace = 70000000 - tNode->getSize();
	int neededSpace = 30000000 - unusedSpace;

	part2Helper(tNode, neededSpace);

	cout << endl << ans2 << endl << endl;

	tNode = root;
}
