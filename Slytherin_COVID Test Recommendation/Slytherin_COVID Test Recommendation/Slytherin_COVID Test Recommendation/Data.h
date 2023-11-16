#pragma once

#ifndef DATA_H
#define DATA_H 

#include <vector>
#include <string>

using namespace std;

// ----------------- Task 1.1: Input Sample Data ----------------- //
// Symptoms struct
struct Symptoms {
    string lowRisk[2];    // Array for low-risk symptoms
    string mediumRisk[2]; // Array for medium-risk symptoms
    string highRisk[1];   // Array for high-risk symptoms
};

// Patient Details struct
struct PatientDetails {
    int patientID;
    string name;
    int dateOfBirth;
    string address;
    Symptoms selectedSymptoms;
    string visitedLocation;
    string overseasTravel;
    string covidTestStatus;
    string vitalStatus;
};

// High risk locations struct
struct HighRiskLocation {
    string locationName;
};

// Function declarations
void addPatientData(vector<PatientDetails>&);
void addSymptomData(vector<Symptoms>&);
void addLocationData(vector<HighRiskLocation>&);

#endif