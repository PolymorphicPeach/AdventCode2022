#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Node{
private:
	Node* parent;
	std::string name;
	std::string type;
	int size;

public:
	Node(std::string name, std::string type, int size) : name(name), type(type), size(size), parent(nullptr){

	}

	void setParent(Node* parent){
		this->parent = parent;
	}

	Node* getParent(){
		return parent;
	}

	virtual Node* getChild(size_t child){
		return nullptr;
	}

	virtual int getNumChildren(){
		return 0;
	}

	std::string getName(){
		return name;
	}

	std::string getType(){
		return type;
	}

	virtual void addNode(std::string name, int size){

	}

	int getSize(){
		return size;
	}

	virtual void setSize(int size){
		this->size += size;
	}
};

