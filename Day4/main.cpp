#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


int main(){
	std::ifstream data;
	data.open("aoc4.txt", std::ios::in);
	string line;


	if(data.fail()){
		cout << "Error: File not found" << "\n\n";
	}
	
	int currentLine{0};
	vector<int> overlapLines;
	vector<int> overlapAtAll;

	while(!data.eof()){
		++currentLine;

		getline(data, line);

		size_t delimIndex;

		for(size_t i{0}; i < line.size(); ++i){
			if(line[i] == ','){
				delimIndex = i;
				break;
			}
		}

		string group1 = line.substr(0, delimIndex);
		string group2 = line.substr(delimIndex + 1, line.size() - delimIndex);

		std::replace(group1.begin(), group1.end(), '-', ' ');
		std::replace(group2.begin(), group2.end(), '-', ' ');

		std::istringstream group1Stream{group1};
		std::istringstream group2Stream{group2};

		int group1Elf1;
		int group1Elf2;

		group1Stream >> group1Elf1 >> group1Elf2;

		int group2Elf1;
		int group2Elf2;

		group2Stream >> group2Elf1 >> group2Elf2;

		std::set<int> group1Set;
		std::set<int> group2Set;



		for(int i{group1Elf1}; i <= group1Elf2; ++i){
			group1Set.insert(i);
		}

		for(int i{group2Elf1}; i <= group2Elf2; ++i){
			group2Set.insert(i);
		}
		
		cout << "group1 set = ";
		for(auto s : group1Set){
			cout << s << ", ";
		}
		cout << endl;

		cout << "group2 set = ";
		for(auto s : group2Set){
			cout << s << ", ";
		}
		cout << endl;

		bool overlapFound{false};
		bool noOverlapAtAll{false};

		if(std::includes(group1Set.begin(), group1Set.end(), group2Set.begin(), group2Set.end())){
			overlapFound = true;
		}

		if(std::includes(group2Set.begin(), group2Set.end(), group1Set.begin(), group1Set.end())){
			overlapFound = true;
		}

		if(overlapFound){
			overlapLines.push_back(currentLine);
		}

		std::vector <int> intersection;

		std::set_intersection(group1Set.begin(), group1Set.end(), group2Set.begin(), group2Set.end(), std::back_inserter(intersection));

		if(!intersection.empty()){
			overlapAtAll.push_back(currentLine);
		}



	}

	cout << "answer: " << overlapLines.size() << endl << endl;
	cout << "ans2: " << overlapAtAll.size() << endl << endl;


	return 0;
}