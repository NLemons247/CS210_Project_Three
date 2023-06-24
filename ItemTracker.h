/*Header file to declare the ItemTracker Class
*/

#ifndef ITEMTRACKER_H 
#define ITEMTRACKER_H

#include <map>
#include <iostream>
#include <fstream>

using namespace std;

class ItemTracker { //Item Tracker Class private and public functions and data members
private:
	map<string, int> frequencyMap;

public:
	ItemTracker() {};
	void readInputFile(string fileName);
	void printListOne(string item);
	void printListTwo();
	void printHistogram();
	void backupData(string filename);

};

#endif
