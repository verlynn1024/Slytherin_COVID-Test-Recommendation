// location.cpp
#include "location.h"
#include <iostream>
#include <fstream>

using namespace std;

// Function to add a new high-risk location
void addLocation(vector<HighRiskLocation>& locations) {
    HighRiskLocation newLocation;
    cout << "Enter the name of the new high-risk location: ";
    cin.ignore();
    getline(cin, newLocation.locationName);

    // Validate that the location name is not empty
    while (newLocation.locationName.empty()) {
        cout << "Invalid input. Please enter a non-empty location name: ";
        getline(cin, newLocation.locationName);
    }

    // Add the new location to the vector
    locations.push_back(newLocation);

    cout << "High-risk location added successfully.\n";
}