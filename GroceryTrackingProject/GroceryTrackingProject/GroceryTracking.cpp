#include "GroceryTracking.h"
#include <iostream>
#include <string>
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Definitions of all functions

GroceryTracking::GroceryTracking() { // Default constructor definition

}


void GroceryTracking::MenuScreen() { // Menu screen definition
	cout << "Hello! Welcome to The Corner Grocer purchase tracker!" << endl;
	cout << endl;
	cout << "Please choose from one of the options below: " << endl;
	cout << "1: Amount of times specified item was purchased" << endl;
	cout << "2: Quantity of items purchased" << endl;
	cout << "3: Histogram of items purchased" << endl;
	cout << "4: End Program" << endl << endl;
}

int GroceryTracking::UserMenuChoice() { // Prompts for input for menu screen 
	int input;
	cout << "Enter option: " << endl << endl;
	cin >> input;
	while (1) {
		if (cin.fail()) { // If the user enters anything but a number, it will clear and ignore cin and request that the user enter again until a number is entered
			cin.clear();
			cin.ignore();
			cout << "You must enter a number." << endl << endl;
			cout << "Enter option: " << endl << endl;
			cin >> input;
		}
		else {
			break;
		}
	}
	return input;
}

string GroceryTracking::MenuOption1() { // Prompts user to input specified item
	string itemName;
	cout << "Enter item name (case sensitive): " << endl;
	cin >> itemName;
	return itemName;
}

int GroceryTracking::GetItemQuantity(string name) { // Returns quantity of specified item
	fstream inFS;
	string line;
	int quantity = 0;
	

	inFS.open("CS210_Project_Three_Input_File.txt");
	if (!inFS.is_open()) { // Checks to make sure file is opened
		cout << "ERROR: could not open file." << endl << endl;
		return 1;
	}
	else {
		while (!inFS.eof()) {
			getline(inFS, line);
			if (line == name) {
				quantity += 1;
			}
		}
	}
	inFS.close();
	return quantity;
}


string GroceryTracking::GetItem() { // Returns the specified item
	return groceryItemName;
}

void GroceryTracking::SetItem(string item) { // Setting specified item
	item = groceryItemName;
}


vector<string> GroceryTracking::AllItemsRepeated() { // Creates vector of all items, with repeats
	fstream inFS;
	string line;
	int i = 0;
	int j = 0;
	vector<string> items;

	inFS.open("CS210_Project_Three_Input_File.txt");
	if (!inFS.is_open()) {
		cout << "ERROR: could not open file." << endl << endl;
	}
	else {
		while (!inFS.eof()) {
			getline(inFS, line);
			items.push_back(line);
		}
		inFS.close();
	}
	return items;
}

vector<string> GroceryTracking::AllItemsSorted(vector<string> vItems) { // Sorts items in vector
	unsigned int i;
	unsigned int j;
	string temp;

	for (i = 0; i < vItems.size(); ++i) {
		for (j = 0; j < vItems.size(); ++j) {
			if (vItems.at(j) > vItems.at(i)) {
				temp = vItems.at(j);
				vItems.at(j) = vItems.at(i);
				vItems.at(i) = temp;
			}
		}
	}
	return vItems;
}

vector<string> GroceryTracking::ItemsNoRepeats(vector<string> vItems) { // Creates vector of all items, with no repeats
	vector<string> noRepeats;

	auto it = unique(vItems.begin(), vItems.end());

	vItems.resize(distance(vItems.begin(), it));

	return vItems;
}

vector<int> GroceryTracking::NumberOfItemsPurhcased(vector<string> vItems, vector<string> vItems2) {
	vector<int> vInts;
	unsigned int i;
	unsigned int j;
	int count = 0;
	string word1;
	string word2;

	for (i = 0; i < vItems2.size(); ++i) { // This determines how many repeats of each item there are, and stores them into an equally sized vector
		count = 0;
		word1 = vItems2.at(i);
		for (j = 0; j < vItems.size(); ++j) {
			word2 = vItems.at(j);
			if (word1 == word2) {
				count += 1;
			}
		}
		vInts.push_back(count);
	}
	return vInts;
}

void GroceryTracking::DisplayQuantityOfItemsPurchased(vector<string> vItems, vector<int> vInts) { // Option 2: Displays each item and how often they were purchased that day
	int i;

	for (i = 0; i < vItems.size(); ++ i) {
		cout << setw(20) << setfill(' ') << vItems.at(i) << " " << vInts.at(i) << endl;
	}
	cout << endl;
}


void GroceryTracking::ItemsPurchasedHistogram(vector<string> vItems, vector<int> vInts) { // This displays a histogram of how many time each item was purchased
	int i;
	int j;

	for (i = 0; i < vItems.size(); ++i) {
		cout << setw(20) << setfill(' ') << vItems.at(i) << " ";
		for (j = 0; j < vInts.at(i); ++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl << endl;
}


void GroceryTracking::BackUpFreq(vector<string> vItems, vector <int> vInts) { // This creates the backup file
	ofstream outFS;

	outFS.open("frequency.dat");

	if (!outFS.is_open()) { // Checks to make sure the file is created and opened
		cout << "ERROR: Failed to create new file." << endl;
	}
	else {
		int i;
		for (i = 0; i < vItems.size(); ++i) {
			outFS << vItems.at(i) << " " << vInts.at(i) << endl;
		}
	}

	outFS.close();

}

