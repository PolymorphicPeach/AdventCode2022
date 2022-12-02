#include <iostream>

#include "ElfExpedition.h"

using std::cout;

int main(){
	ElfExpedition expedition;
	expedition.populateInventories();
	cout << "Most calories: " << expedition.getElfWithMostCalories() << "\n";
	cout << "Top 3 Total: " << expedition.getTop3ElvesTotal() << "\n\n";

	return 0;
}