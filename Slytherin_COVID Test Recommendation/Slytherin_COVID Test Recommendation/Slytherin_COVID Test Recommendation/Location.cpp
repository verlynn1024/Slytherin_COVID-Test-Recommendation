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
    locations.push_back(newLocation);
    cout << "High-risk location added successfully.\n";
}

// Function to display high-risk locations
void displayHighRiskLocations(const vector<HighRiskLocation>& locations) {
    cout << "High Risk Locations:\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << i + 1 << ". " << locations[i].locationName << "\n";
    }
}