#include "fileIO.h"
#include <fstream>
#include <iostream>

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
            << patient.address;

        // Check if the patient has low-risk symptoms
        if (!patient.selectedSymptoms.lowRisk[0].empty() || !patient.selectedSymptoms.lowRisk[1].empty()) {
            patientFile << "," << patient.selectedSymptoms.lowRisk[0] << "," << patient.selectedSymptoms.lowRisk[1];
        }
        else {
            patientFile << ",,";
        }

        // Check if the patient has medium-risk symptoms
        if (!patient.selectedSymptoms.mediumRisk[0].empty() || !patient.selectedSymptoms.mediumRisk[1].empty()) {
            patientFile << "," << patient.selectedSymptoms.mediumRisk[0] << "," << patient.selectedSymptoms.mediumRisk[1];
        }
        else {
            patientFile << ",,";
        }

        // Check if the patient has high-risk symptoms
        if (!patient.selectedSymptoms.highRisk[0].empty()) {
            patientFile << "," << patient.selectedSymptoms.highRisk[0];
        }
        else {
            patientFile << ",";
        }

        patientFile << "," << patient.visitedLocation << "," << patient.overseasTravel << ","
            << patient.covidTestStatus << "," << patient.vitalStatus << "\n";
    }

    // Write symptom data to the file
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
    for (HighRiskLocation loc : locations) {
        locationFile << loc.locationName << "\n";
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

