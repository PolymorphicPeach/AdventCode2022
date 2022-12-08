#pragma once
#include "Node.h"
#include "File.h"

class Directory : public Node{
private:
	std::vector<Node*> children;
	int numChildren;


public:
	Directory(std::string name, int size) : Node(name, "Dir", size), numChildren(0){

	}

	virtual void addNode(std::string name, int size) override final{
		if(size > 0){
			children.push_back(new File(name, size));
			children[children.size() - 1]->setParent(this);
			++numChildren;

		}
		else{
			children.push_back(new Directory(name, 0));
			children[children.size() - 1]->setParent(this);
			++numChildren;
		}

	}

	virtual Node* getChild(size_t child){
		if(child >= 0 && child < children.size()){
			return children[child];
		}
		else{
			return nullptr;
		}
	}

	virtual int getNumChildren() override final{
		return numChildren;
	}
};