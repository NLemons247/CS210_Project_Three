/*Nathaniel Lemons
* CS210 Project Three
* 06/18/2023
* Application to track how often a piece of produce is bought from a file that lists the different items purchased.
*/

#include <iostream>
#include <fstream>
#include <map>
#include "ItemTracker.h"

using namespace std;

//Main function used to menu loop and to open file for scanning
int main() {
	ItemTracker tracker;
	tracker.readInputFile("CS210_Project_Three_Input_File.txt"); //Open file for scanning

	int choice;
	do { //Menu Loop
		cout << "Menu:" << endl;
		cout << "1. Specific Item Search" << endl;
		cout << "2. Show Frequency of All Items" << endl;
		cout << "3. Print Histogram of All Items" << endl;
		cout << "4. Exit Program" << endl;
		cout << "\nPlease select an option (1-4): ";
		cin >> choice;
		cout << "------------------------------" << endl;

		switch (choice) {
		case 1: { //Access option one to search for a singular item
			string item;
			cout << "Enter item to search: ";
			cin >> item;
			tracker.printListOne(item);
			cout << "------------------------------" << endl;
			break;
		}
		case 2: { //Access option two to show how many times every item has been purchased
			tracker.printListTwo();
			cout << "------------------------------" << endl;
			break;
		}
		case 3: { //Access option three to show a histogram of the different purchased food items
			tracker.printHistogram();
			cout << "------------------------------" << endl;
			break;
		}
		case 4: { //Access option four to terminate program and backup data to a new file
			tracker.backupData("frequency.dat");
			cout << "Exiting program" << endl;
			break;
		}
		default: { //In case someone picks an unavailable option
			cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
			cout << "------------------------------" << endl;
			break;
		}
		}
	} while (choice != 4);
	return 0;
}