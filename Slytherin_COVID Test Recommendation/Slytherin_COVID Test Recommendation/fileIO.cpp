// fileIO.cpp

#include "fileIO.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

bool writeDataToFile(const vector<PatientDetails>& patients,
    const vector<Symptoms>& symptoms,
    const vector<HighRiskLocation>& locations,
    const string& patientFileName,
    const string& symptomFileName,
    const string& locationFileName) {

    ofstream patientFile(patientFileName);
    if (!patientFile) {
        cout << "Invalid patient file..." << endl;
        return false;
    }

    ofstream symptomFile(symptomFileName);
    if (!symptomFile) {
        cout << "Invalid symptom file..." << endl;
        return false;
    }

    ofstream locationFile(locationFileName);
    if (!locationFile) {
        cout << "Invalid location file..." << endl;
        return false;
    }

    // Write patient data to file
    for (const PatientDetails& patient : patients) {
        patientFile << patient.patientID << "," << patient.name << "," << patient.dateOfBirth << ","
            << patient.address << ",";

        // Check if there are any symptoms before adding curly braces
        bool hasSymptoms = !patient.selectedSymptoms.lowRisk[0].empty() ||
            !patient.selectedSymptoms.lowRisk[1].empty() ||
            !patient.selectedSymptoms.mediumRisk[0].empty() ||
            !patient.selectedSymptoms.mediumRisk[1].empty() ||
            !patient.selectedSymptoms.highRisk[0].empty();

        if (hasSymptoms) {
            patientFile << "{" << patient.selectedSymptoms.lowRisk[0] << "," << patient.selectedSymptoms.lowRisk[1] << ","
                << patient.selectedSymptoms.mediumRisk[0] << "," << patient.selectedSymptoms.mediumRisk[1] << ","
                << patient.selectedSymptoms.highRisk[0] << "}";
        }

        patientFile << "," << patient.visitedLocation << "," << patient.overseasTravel << ","
            << patient.covidTestStatus << "," << patient.vitalStatus << "\n";
    }

    symptomFile << "Low Risk Symptoms:\n";
    for (const Symptoms& sym : symptoms) {
        symptomFile << sym.lowRisk[0] << "\n";
        symptomFile << sym.lowRisk[1] << "\n";
    }

    symptomFile << "\nMedium Risk Symptoms:\n";
    for (const Symptoms& sym : symptoms) {
        symptomFile << sym.mediumRisk[0] << "\n";
        symptomFile << sym.mediumRisk[1] << "\n";
    }

    symptomFile << "\nHigh Risk Symptoms:\n";
    for (const Symptoms& sym : symptoms) {
        symptomFile << sym.highRisk[0] << "\n";
    }
    // Write location data to file
    for (const HighRiskLocation& loc : locations) {
        locationFile << loc.locationName << "\n";
    }

    patientFile.close();
    symptomFile.close();
    locationFile.close();

    return true;
}

void displayPatientDetails(const vector<PatientDetails>& patients) {
    if (patients.empty()) {
        cout << "[] - the database is empty." << endl;
        return;
    }

    cout << "------------------------------- Patient Detail -------------------------------\n";
    for (const PatientDetails& patient : patients) {
        cout << patient.patientID << "," << patient.name << "," << patient.dateOfBirth << ","
            << patient.address << ",";

        // Check if there are any symptoms before adding curly braces
        bool hasSymptoms = !patient.selectedSymptoms.lowRisk[0].empty() ||
            !patient.selectedSymptoms.lowRisk[1].empty() ||
            !patient.selectedSymptoms.mediumRisk[0].empty() ||
            !patient.selectedSymptoms.mediumRisk[1].empty() ||
            !patient.selectedSymptoms.highRisk[0].empty();

        if (hasSymptoms) {
            cout << "{" << patient.selectedSymptoms.lowRisk[0] << "," << patient.selectedSymptoms.lowRisk[1] << ","
                << patient.selectedSymptoms.mediumRisk[0] << "," << patient.selectedSymptoms.mediumRisk[1] << ","
                << patient.selectedSymptoms.highRisk[0] << "}";
        }

        cout << "," << patient.visitedLocation << "," << patient.overseasTravel << ","
            << patient.covidTestStatus << "," << patient.vitalStatus << "\n";
    }

    cout << "--------------------------------------------------------------------------\n";
}

void displayAllLocations(const vector<HighRiskLocation>& locations) {
    if (locations.empty()) {
        cout << "No locations available." << endl;
        return;
    }

    cout << "-------------------------- All Locations --------------------------\n";
    for (size_t i = 0; i < locations.size(); ++i) {
        cout << setw(3) << i + 1 << ". " << locations[i].locationName << "\n";
    }
    cout << "-------------------------------------------------------------------\n";
}

void displaySymptoms(const Symptoms& symptoms) {
    cout << "-------------------------- All Symptoms ---------------------------\n";
    cout << "Low Risk Symptoms:\n";
    for (int i = 0; i < 2; ++i) {
        cout << i + 1 << ". " << symptoms.lowRisk[i] << endl;
    }

    cout << "\nMedium Risk Symptoms:\n";
    for (int i = 0; i < 2; ++i) {
        cout << i + 3 << ". " << symptoms.mediumRisk[i] << endl;
    }

    cout << "\nHigh Risk Symptoms:\n";
    cout << "5. " << symptoms.highRisk[0] << endl;
    cout << "-------------------------------------------------------------------\n";
}