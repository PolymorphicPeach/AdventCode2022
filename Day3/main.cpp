#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <thread>
#include <chrono>

using std::cout;
using std::cin;
using std::string;
using std::vector;

static int threadsLaunched{0};
int part1();
int part2();

int main(){
	auto startTime = std::chrono::high_resolution_clock::now();

	//std::thread t1(part1);
	//std::thread t2(part2);

	//t1.join();
	//t2.join();

	cout << part1() << "\n"
		<< part2() << "\n\n";

	auto finishTime = std::chrono::high_resolution_clock::now();

	// Code below this comment is not counted in the duration; the duration is only for the puzzle solving time, 
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(finishTime - startTime);

	cout << "Threads launched: " << threadsLaunched
		 << "\nCompleted in: " << duration.count() << " seconds." << "\n\n";

	return 0;
}

int part1(){
	std::ifstream data;
	data.open("aoc3.txt", std::ios::in);
	string line;
	int sumItems{0};
	int asciiConvert;

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

	for(int i{0}; i < commonItems.size(); ++i){
		if(std::isupper(commonItems[i])){
			asciiConvert = commonItems[i] - 38;
			sumItems += asciiConvert;
		}
		else{
			asciiConvert = commonItems[i] - 96;
			sumItems += asciiConvert;

		}


	}

	data.close();

	return sumItems;
}

int part2(){
	std::ifstream data;
	data.open("aoc3.txt", std::ios::in);

	int sumOfGroups{0};
	string group1Stuff;
	string group2Stuff;
	string line;

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

		char thread1ReturnChar;
		char thread2ReturnChar;

		//std::thread group1Thread([&group1, &thread1ReturnChar]()
		{
			//++threadsLaunched;
			string commonPt1;
			string commonPt2;

			for(size_t i{0}; i < group1.size(); ++i){
				std::sort(group1[i].begin(), group1[i].end());
			}

			std::set_intersection(group1[0].begin(), group1[0].end(),
				group1[1].begin(), group1[1].end(), std::back_inserter(commonPt1));

			std::sort(commonPt1.begin(), commonPt1.end());

			std::set_intersection(commonPt1.begin(), commonPt1.end(),
				group1[2].begin(), group1[2].end(), std::back_inserter(commonPt2));

			thread1ReturnChar = commonPt2[0];

		}//);

		//std::thread group2Thread([&group2, &thread2ReturnChar]()
		{
			//++threadsLaunched;
			string commonPt1;
			string commonPt2;

			for(size_t i{0}; i < group2.size(); ++i){
				std::sort(group2[i].begin(), group2[i].end());
			}

			std::set_intersection(group2[0].begin(), group2[0].end(),
				group2[1].begin(), group2[1].end(), std::back_inserter(commonPt1));

			std::sort(commonPt1.begin(), commonPt1.end());



			std::set_intersection(commonPt1.begin(), commonPt1.end(),
				group2[2].begin(), group2[2].end(), std::back_inserter(commonPt2));

			thread2ReturnChar = commonPt2[0];
		}//);

		//group1Thread.join();
		//group2Thread.join();

		group1Stuff += thread1ReturnChar;
		group2Stuff += thread2ReturnChar;
	}

	//std::thread group1Thread([&group1Stuff, &sumOfGroups]()
	{
		//++threadsLaunched;
		int asciiConvert;

		for(int i{0}; i < group1Stuff.size(); ++i){

			if(std::isupper(group1Stuff[i])){
				asciiConvert = group1Stuff[i] - 38;
				sumOfGroups += asciiConvert;
			}
			else{
				asciiConvert = group1Stuff[i] - 96;
				sumOfGroups += asciiConvert;

			}
		}
	}//);

	//std::thread group2Thread([&group2Stuff, &sumOfGroups]()
	{
		//++threadsLaunched;
		int asciiConvert;

		for(int i{0}; i < group2Stuff.size(); ++i){
			if(std::isupper(group2Stuff[i])){
				asciiConvert = group2Stuff[i] - 38;
				sumOfGroups += asciiConvert;
			}
			else{
				asciiConvert = group2Stuff[i] - 96;
				sumOfGroups += asciiConvert;

			}
		}
	}//);

	//group1Thread.join();
	//group2Thread.join();

	return sumOfGroups;
}