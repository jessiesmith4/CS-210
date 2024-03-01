#ifndef GROCERY_TRACKING_H
#define GROCERY_TRACKING_H

#include <string>
#include <vector>
using namespace std;

// Declarations of all functions

class GroceryTracking {
	public:
		GroceryTracking(); // Default constructor declaration
		void MenuScreen(); // Menu declaration
		int UserMenuChoice(); // Function to get input declaration
		string MenuOption1(); // This prompts user to input item they are searching for
		int GetItemQuantity(string name); // Returns the amount of times the specified item, from option 1, was purchased
		string GetItem(); // Returns specified item (groceryItemName)
		void SetItem(string item); // Sets specified item (groceryItemName)
		vector<string> AllItemsRepeated(); // This creates a vector that is identical to the file of items purchased that day
		vector<string> AllItemsSorted(vector<string> vItems); // This creates a sorted vector with items purchased that day, including all repeats
		vector<string> ItemsNoRepeats(vector<string> vItems); // This creates a vector of items purchased that day, not repeating the item however many times it was purchased
		vector<int> NumberOfItemsPurhcased(vector<string> vItems, vector<string> vItems2); // This creates a vector with corresponding quantities to the items vector
		void DisplayQuantityOfItemsPurchased(vector<string> vItems, vector<int> vInts);
		void ItemsPurchasedHistogram(vector<string> vItems, vector<int> vInts); // This displays a histogram showing how many time each item was purchased that day
		void BackUpFreq(vector<string> vItems, vector<int> vints); // This creates the back up file of data
	private:
		string groceryItemName; // Private string, input is provided by user
};

#endif