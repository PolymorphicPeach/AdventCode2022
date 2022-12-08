#pragma once

#include <string>
#include <vector>

#include "Node.h"

class File : public Node{
private:


public:
	File(std::string name, int size) : Node(name, "File", size){

	}

	virtual void addNode(std::string name, int size) override final{
		cout << "Error: attempting to add children to a File" << endl;
		return;
	}

	virtual Node* getChild(size_t child){
		return nullptr;
	}

	virtual void setSize(int size) override final{
		return;
	}

	virtual int getNumChildren() override final{
		return 0;
	}

};

