#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
using namespace std;

// Jessie Smith
// SNHU
// CS 210
// 16 April 2023

#include "GroceryTracking.h"

int main() {
	GroceryTracking userData;
	int menuChoice;
	string userInput;
	int itemQuantity;
	vector<string> items; // Vector that will be sorted, including repeats of each item
	vector<string> items2; // This will be the vector storing unrepeated list of purchased items
	vector<int> quantityOfItems; // Vector stoging amount of times each item was purchased

	// First, I created vectors containing all of the data needed to display the amounts of time a specified item or all items were purchased
	items = userData.AllItemsRepeated(); // First the vector is created using the txt file provided
	items = userData.AllItemsSorted(items); // Next the vector is sorted
	items2 = userData.ItemsNoRepeats(items); // A second vector is created, containing no repeats of the items
	quantityOfItems = userData.NumberOfItemsPurhcased(items, items2); // This creates a third vector containing the times an item was purchased
	// This third vectors elements correspond to the second vectors elements, and was created by comparing the first vector and second vector

	userData.BackUpFreq(items2, quantityOfItems);

	while (true) {
		userData.MenuScreen();
		menuChoice = userData.UserMenuChoice();
		while (true) {
			if (menuChoice == 1) { // Option one tells the user how many times a specific item was purchased
				cout << "OPTION 1" << endl << endl;

				userInput = userData.MenuOption1();

				userData.SetItem(userInput);

				itemQuantity = userData.GetItemQuantity(userInput);

				cout << "There were " << itemQuantity << " " << userInput << " purchased today." << endl << endl; // Shows user how many times the item was purchased
				break;
			}
			else if (menuChoice == 2) { // Option two tells the user how many times each item was purchased
				cout << "OPTION 2" << endl << endl;
				
				userData.DisplayQuantityOfItemsPurchased(items2, quantityOfItems); // This is option 3, the items are displayed with a corresponding amount of times they were purchased

				break;
			}
			else if (menuChoice == 3) { // Option 3 displays a histogram of how many times each item was purhcased
				cout << "OPTION 3" << endl << endl;

				userData.ItemsPurchasedHistogram(items2, quantityOfItems); // This is the function to display the histogram

				break;
			}
			else if (menuChoice == 4) { // This excits the program
				return 0;
			}
			else { // If the user enters a number not in between 1 and 4, they will be prompted to re enter their choice
				cout << "Input must be between 1 and 4" << endl << endl;
				menuChoice = userData.UserMenuChoice();
			}
		}
	}

	return 0;
}