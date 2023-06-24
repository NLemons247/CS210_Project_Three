#include "ItemTracker.h"
#include <iostream>
#include <map>
#include <fstream>

using namespace std;

void ItemTracker::readInputFile(string fileName) { //A function to open and read input file and to map the different items in the file
	ifstream infile("CS210_Project_Three_Input_File.txt");
		string item;
	while (infile >> item) { //Creates different keys and memory locations for the different items on the input file
		frequencyMap[item]++;
	}
	infile.close(); //Close file after information has been processed
}

void ItemTracker::printListOne(string item) { //Function to find a single item and learn how many times it appears in the input file. (Menu option one)
	if (frequencyMap.count(item) > 0) { //If/else statement to show the number of times that the item appears on the list
		cout << item << " was purchased " << frequencyMap[item] << " times." << endl;
	}
	else {
		cout << item << " was not purchased." << endl;
	}
}

void ItemTracker::printListTwo() { //Function to display all items and how many times they show up on the input file list (Menu Option Two)
	for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) { //For loop that passes a pointer between different keys and values
		cout << i->first << " was purchased " << i->second << " times." << endl; 
	}
}

void ItemTracker::printHistogram() { //Function to display a histogram of all items on list from input file (Menu Option Three)
	for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) {//For loop to access the first value in the mapped pair
		cout << i->first << " ";
		for (int j = 0; j < i->second; j++) { //For loop to replace the key in the map with the # character for how many times it shows up in the file
			cout << "#";
		}
		cout << endl;
	}
}

void ItemTracker::backupData(string filename) { //Function to terminate application and send "backup data" to a file named frequency.dat (Menu Option Four)
	ofstream frequencyFile(filename); //Create file for outstream
	for (auto i = frequencyMap.begin(); i != frequencyMap.end(); i++) { //For loop to iterate through all the information processed and saved in memory to add to out stream file
		frequencyFile << i->first << " " << i->second << endl;
	}
	frequencyFile.close(); //Close outstream file
}




