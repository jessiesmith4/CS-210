#include <iostream>
#include <string>
#include <iomanip> // I used iomanip to have the single digits on the clock displayed as double digits

using namespace std;

/*

*Jessie Smith
*CS 210
*SNHU
*17 March 2023

*/



// Function declarations, so that main is at the top
void AddHour(int& hour);
void AddMinute(int& hour, int& minute);
void AddSecond(int& hour, int& minute, int& second);
void DisplayMenu();
int DisplayTime(int hour, int minute, int second);
string AddSymbols(char symbol, int amount);
int GetUserInput(string question);
void PrintFirstLine();
void PrintSecondLine();
int PrintThirdLine(int hour, int minute, int second);
void PrintFourthLine();



int main() {
	int userOption;
	int hour = 0; // Initialized values to start off the clocks
	int minute = 0;
	int second = 0;

	while (true) {
		DisplayTime(hour, minute, second); // Calls function to display time
		DisplayMenu(); // Displays the menu for the user
		userOption = GetUserInput("Enter menu selection"); // Gets the users input
		if (userOption == 1) {
			AddHour(hour); // Calls function to add hour to clocks
		}
		else if (userOption == 2) {
			AddMinute(hour, minute); // Calls function to add minute to clocks
		}
		else if (userOption == 3) {
			AddSecond(hour, minute, second); // Calls function to add second to clocks
		}
		else if (userOption == 4) {
			break; // End program
		}
		else {
			cout << "Invalid Input." << endl; // Informs user that input is invalid and tells user the options, the program will restart at the loop here
			cout << "Options are: 1, 2, 3, or 4." << endl; 
			cout << endl;
		}

	}






}

int GetUserInput(string question) { // Function to get user input
	int input;
	cout << question << endl;
	cin >> input;
	return input;

}

string AddSymbols(char symbol, int amount) { // This function adds the '*' to the display of the menu and clocks
	string lineOfSymbols = "";
	int i;

	for (i = 0; i < amount; ++i) {
		lineOfSymbols += symbol;
	}
	return lineOfSymbols;
}



void DisplayMenu() { // Displays menu with options and by calling AddSymbols function
	cout << endl;
	cout << AddSymbols(' ', 48);
	cout << AddSymbols('*', 26) << endl;
	cout << AddSymbols(' ', 48);
	cout << "* 1 - Add One Hour       *" << endl;
	cout << AddSymbols(' ', 48);
	cout << "* 2 - Add One Minute     *" << endl;
	cout << AddSymbols(' ', 48);
	cout << "* 3 - Add One Second     *" << endl;
	cout << AddSymbols(' ', 48);
	cout << "* 4 - Exit Program       *" << endl;
	cout << AddSymbols(' ', 48);
	cout << AddSymbols('*', 26) << endl;
	cout << endl;
}
int DisplayTime(int hour, int minute, int second) { // Displays time by calling the functions of each line of the clocks
	PrintFirstLine();
	PrintSecondLine();
	PrintThirdLine(hour, minute, second);
	PrintFourthLine();

	return 0;
}



void PrintFirstLine() { // This is the first line of the clocks
	cout << AddSymbols(' ', 30) << AddSymbols('*', 26) << AddSymbols(' ', 10) << AddSymbols('*', 26) << endl;
}
void PrintSecondLine() { // This is the second line of the clocks, labeling them as 12-Hour or 24-Hour
	cout << AddSymbols(' ', 30) << "*" << AddSymbols(' ', 5) << "12-Hour Clock" << AddSymbols(' ', 6) << "*";
	cout << AddSymbols(' ', 10) << "*" << AddSymbols(' ', 5) << "24-Hour Clock" << AddSymbols(' ', 6) << "*" << endl;
}
int PrintThirdLine(int hour, int minute, int second) { // This is the third line of the clocks which takes in the hour, minute, second, and displays both 12-Hour and 24-Hour
	string amOrPm = "A M";
	int temp12 = hour; // temp12 stores a temp value for setting the 12-Hour clock according to the 24-Hour clock

	if (hour == 24) { // The hour of 24 resets to 0, limiting the 24-Hour clock to 23:59:59
		hour = 0;
	}

	if (hour == 0) { // The hour of 0, is midnight, so 12 AM on the 12-Hour clock
		temp12 = 12;
		amOrPm = "A M";
	}
	else if (hour > 11) { // Past the hour of 11 is PM
		amOrPm = "P M";
	}

	if (hour > 12) {  // Sets the 12-Hour clock according to the 24-Hour clock
		temp12 -= 12;
	}

	// The clocks are printed here
	cout << AddSymbols(' ', 30) << "*" << AddSymbols(' ', 6);
	cout << setw(2) << setfill('0') << temp12;
	cout << ":";
	cout << setw(2) << setfill('0') << minute;
	cout << ":";
	cout << setw(2) << setfill('0') << second;
	cout << " " << amOrPm << AddSymbols(' ', 6) << "*";
	cout << AddSymbols(' ', 10) << "*" << AddSymbols(' ', 7);
	cout << setw(2) << setfill('0') << hour;
	cout << ":";
	cout << setw(2) << setfill('0') << minute;
	cout << ":";
	cout << setw(2) << setfill('0') << second;
	cout << AddSymbols(' ', 9) << "*" << endl;

	return 0;
}
void PrintFourthLine() { // The fourth line of the clocks
	cout << AddSymbols(' ', 30) << AddSymbols('*', 26) << AddSymbols(' ', 10) << AddSymbols('*', 26) << endl;
}



void AddHour(int& hour) { // Adds an hour to the clock
	hour += 1;
	if (hour > 24) {
		hour = 1;
	}
}
void AddMinute(int& hour, int& minute) { // Adds a minute to the clock, if the minute exceeds 59, the minute is reset to 0 and the hour updates
	minute += 1;
	if (minute > 59) {
		minute = 0;
		AddHour(hour);
	}
}
void AddSecond(int& hour, int& minute, int& second) { // Adds a second to the clocks
	second += 1;
	if (second > 59) { // If the second exceeds 59, it is reset to 0 and a minute is added to the clocks
		second = 0;
		AddMinute(hour, minute);
		if (minute > 59) { // If the minute exceeds 59, it is reset to 0 and an hour is added to the clocks
			minute = 0;
			AddHour(hour);
		}
	}
}