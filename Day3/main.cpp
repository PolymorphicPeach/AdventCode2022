#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using std::cout;
using std::cin;
using std::string;
using std::vector;

int main(){
	std::ifstream data;
	data.open("aoc3.txt", std::ios::in);
	string line;

	string compartment1;
	string compartment2;

	string commonItems;

	if(data.fail()){
		std::cerr << "Error: File not found \n";
	}




	while(!data.eof()){
		getline(data, line);

		compartment1 = line.substr(0, line.size() / 2);
		compartment2 = line.substr(line.size() / 2, line.size() - line.size() / 2);

		bool match{false};

		for(size_t i{0}; i < compartment1.size() && !match; ++i){

			for(size_t j{0}; j < compartment2.size() && !match; ++j){
				
				if(compartment1[i] == compartment2[j]){
					commonItems += compartment1[i];
					match = true;
					break;
				}
			}

		}


	}

	int value{0};
	int asciiConvert;

	for(int i{0}; i < commonItems.size(); ++i){
		if(std::isupper(commonItems[i])){
			asciiConvert = commonItems[i] - 38;
			value += asciiConvert;
		}
		else{
			asciiConvert = commonItems[i] - 96;
			value += asciiConvert;

		}


	}

	cout << value << "\n\n";

	data.close();
	data.open("aoc3.txt", std::ios::in);


	int sumOfGroups{0};
	string group1Stuff;
	string group2Stuff;

	while(!data.eof()){


		vector <string> group1;

		vector <string> group2;

		for(int i{0}; i < 3; ++i){
			getline(data, line);
			group1.push_back(line);
			
		}

		for(int i{0}; i < 3; ++i){
			getline(data, line);
			group2.push_back(line);


		}

		string common1;
		string common2;

		string common1Pt2;
		string common2Pt2;

		for(size_t i{0}; i < group1.size(); ++i){
			std::sort(group1[i].begin(), group1[i].end());
			std::sort(group2[i].begin(), group2[i].end());
		}


		std::set_intersection(group1[0].begin(), group1[0].end(),
			group1[1].begin() , group1[1].end(), std::back_inserter(common1));

		std::set_intersection(group2[0].begin(), group2[0].end(),
			group2[1].begin(), group2[1].end(), std::back_inserter(common2));

		std::sort(common1.begin(), common1.end());
		std::sort(common2.begin(), common2.end());

		std::set_intersection(common1.begin(), common1.end(),
			group1[2].begin(), group1[2].end(), std::back_inserter(common1Pt2));

		std::set_intersection(common2.begin(), common2.end(),
			group2[2].begin(), group2[2].end(), std::back_inserter(common2Pt2));



		if(common1Pt2.size() > 1){
			cout << "ALERT pt 1 GREATER THAN 1" << std::endl;
			for(size_t i{0}; i < group1.size(); ++i){
				cout << group1[i] << std::endl;
			}
			cout << common1Pt2 << std::endl;
			cout << std::endl;
		}
		if(common2Pt2.size() > 1){
			cout << "ALERT pt 2 GREATER THAN 1" << std::endl;
			for(size_t i{0}; i < group2.size(); ++i){
				cout << group2[i] << std::endl;
			}
			cout << common2Pt2 << std::endl;
			cout << std::endl;
		}

		group1Stuff += common1Pt2[0];
		group2Stuff += common2Pt2[0];
	}

	int value2{0};
	asciiConvert = 0;

	cout << group1Stuff << "\n" << group2Stuff << "\n\n";

	for(int i{0}; i < group1Stuff.size(); ++i){



		if(std::isupper(group1Stuff[i])){
			asciiConvert = group1Stuff[i] - 38;
			value2 += asciiConvert;
		}
		else{
			asciiConvert = group1Stuff[i] - 96;
			value2 += asciiConvert;

		}
	}

	for(int i{0}; i < group2Stuff.size(); ++i){
		if(std::isupper(group2Stuff[i])){
			asciiConvert = group2Stuff[i] - 38;
			value2 += asciiConvert;
		}
		else{
			asciiConvert = group2Stuff[i] - 96;
			value2 += asciiConvert;

		}
	}

	cout << "g1 size = " << group1Stuff.size() << "\n";
	cout << "g2 size = " << group2Stuff.size() << "\n";

	cout << value2 << "\n\n";


	return 0;
}