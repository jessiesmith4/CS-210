#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

/*
* 
* Jessie Smith
* SNHU
* CS 210
* 24 March 2023
* 
*/

int main() {
	fstream inFS; // Taking a file as input
	ofstream outFS; // Outputting a file
	vector<string> locations; // A vector of the locations in FarenheitTemperature.txt
	vector<int> temperatures; // A vector of the temperatures in FarenheitTemperature.txt

	inFS.open("FarenheitTemperature.txt"); // This opens the file

	if (!inFS.is_open()) { // Checks to make sure file is opened
		cout << "ERROR: could not open file." << endl;
		return 1;
	}
	else { // This is where I seperate the locations and temperatures into vectors
		string locationAndTemp; // String to contain both the location and temperature
		string location; // String to contain the location
		string temp; // String to contain the temperature
		int intTemp; // Integer to contain the temperature

		while (!inFS.eof()) {
			getline(inFS, locationAndTemp); // This takes in the lines a strings, including both location and temperature

			location = locationAndTemp.substr(0, locationAndTemp.size() - 3); // A substr, location, is created to only contain the location, no space and no temperature
			temp = locationAndTemp.substr(locationAndTemp.size() - 2, 2); // A substr, temp, is created to only contain the temperature, no space and no location

			intTemp = stoi(temp); // Temperature is converted to an integer

			locations.push_back(location); // Locations are added to a vector, locations
			temperatures.push_back(intTemp); // Temperatures are added to a vector, temperatures
			
		}
	}

	inFS.close(); // The file is closed

	outFS.open("CelciusTemperature.txt"); // This creates a new file called "CelciusTemperature.txt"

	if (!outFS.is_open()) { // Checks to make sure the file is created and opened
		cout << "ERROR: Failed to create new file." << endl;
		return 1;
	}
	else {
		int i;
		int tempC; // Variable to store temperatures in celcius
		for (i = 0; i < locations.size(); ++i) { // Loop that loops through the vectors
			tempC = (temperatures.at(i) - 32.0) * (5.0 / 9.0); // Conversion of temperatures from farenheit to celcius
			outFS << locations.at(i) << " " << tempC << endl; // This adds the location, a space, and the temperature in celcius to the file
		}
	}
	
	outFS.close(); // The file is closed
	
	return 0;
}