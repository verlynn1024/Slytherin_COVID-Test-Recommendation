// patient.cpp

#include "patient.h"
#include <iostream>
#include <limits>
#include "fileIO.h"

using namespace std;

// Function to get a unique patient ID
int getUniquePatientID(const vector<PatientDetails>& patients) {
    int patientID;
    while (true) {
        cout << "Enter Patient ID: ";
        cin >> patientID;

        bool isDuplicate = false;
        for (const PatientDetails& patient : patients) {
            if (patient.patientID == patientID) {
                cout << "Duplicate ID. Please enter a unique ID." << endl;
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            break;
        }
    }
    return patientID;
}

// Function to get the patient's name
string getPatientName() {
    string name;
    cout << "Name: ";
    cin.ignore(); // Clear the buffer before getline
    getline(cin, name);
    return name;
}

// Function to get the patient's date of birth
int getPatientDateOfBirth() {
	int dateOfBirth;
	while (true) {
		cout << "Enter Date of Birth (YYYY): ";
		if (cin >> dateOfBirth) {
            if (dateOfBirth <= 2023) {
                break; // If the input is valid, exit the loop
            } else {
                cout << "Invalid input. Please enter a valid year not more than 2023." << endl;
            }
		}
		else {
			cout << "Invalid input. Please enter a numeric value for the date of birth." << endl;
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
		}
	}
	return dateOfBirth;
}

// Function to get the patient's address
string getPatientAddress() {
    string address;
    cout << "Address: ";
    cin.ignore();
    getline(cin, address);
    return address;
}

// Function to get the visited location from high-risk areas
string getVisitedLocation(const vector<HighRiskLocation>& locations) {
    // Display high-risk locations
    displayHighRiskLocations(locations);

    // Function to validate and get user input
    auto getUserInput = [](int maxIndex) -> int {
        int userInput;
        while (true) {
            cout << "Select visited location (or enter 0 to skip): ";
            if (cin >> userInput && userInput >= 0 && userInput <= maxIndex) {
                break;
            }
            else {
                cout << "Invalid selection. Please choose a valid option.\n";
                cin.clear();  // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            }
        }
        return userInput;
        };

    int selectedLocation = getUserInput(locations.size());
    if (selectedLocation > 0) {
        // User selected a high-risk location
        return locations[selectedLocation - 1].locationName;
    }
    else {
        // User skipped the selection
        return "Not visited any high-risk location";
    }
}

// Function to get the selected symptoms from the user
Symptoms getSelectedSymptoms(const vector<Symptoms>& symptoms) {
    Symptoms selectedSymptoms;

    // Display Low Risk Symptoms
    cout << "Low Risk Symptoms:\n";
    for (int i = 0; i < symptoms.size(); i++) {
        cout << i * 2 + 1 << ". " << symptoms[i].lowRisk[0] << "\n";
        cout << i * 2 + 2 << ". " << symptoms[i].lowRisk[1] << "\n";
    }

    int selectedLowRisk1;
    cout << "Select symptom (or enter 0 to skip): ";
    cin >> selectedLowRisk1;

    if (selectedLowRisk1 > 0 && selectedLowRisk1 <= 2 * symptoms.size()) {
        selectedSymptoms.lowRisk[0] = symptoms[(selectedLowRisk1 - 1) / 2].lowRisk[0];
        selectedSymptoms.lowRisk[1] = symptoms[(selectedLowRisk1 - 1) / 2].lowRisk[1];
    } else {
        // User skipped the selection, return a null-like value
        return Symptoms{}; // Default constructor initializes all strings to empty
    }

    // Display Medium Risk Symptoms
    cout << "Medium Risk Symptoms:\n";
    for (int i = 0; i < symptoms.size(); i++) {
        cout << i * 2 + 1 << ". " << symptoms[i].mediumRisk[0] << "\n";
        cout << i * 2 + 2 << ". " << symptoms[i].mediumRisk[1] << "\n";
    }

    int selectedMediumRisk1;
    cout << "Select symptom (or enter 0 to skip): ";
    cin >> selectedMediumRisk1;

    if (selectedMediumRisk1 > 0 && selectedMediumRisk1 <= 2 * symptoms.size()) {
        selectedSymptoms.mediumRisk[0] = symptoms[(selectedMediumRisk1 - 1) / 2].mediumRisk[0];
        selectedSymptoms.mediumRisk[1] = symptoms[(selectedMediumRisk1 - 1) / 2].mediumRisk[1];
    }else {
        // User skipped the selection, return a null-like value
        return Symptoms{}; // Default constructor initializes all strings to empty
    }

    // Display High Risk Symptoms
    cout << "High Risk Symptoms:\n";
    for (int i = 0; i < symptoms.size(); i++) {
        cout << i + 1 << ". " << symptoms[i].highRisk[0] << "\n";
    }

    int selectedHighRisk;
    cout << "Select symptom (or enter 0 to skip): ";
    cin >> selectedHighRisk;

    if (selectedHighRisk > 0 && selectedHighRisk <= symptoms.size()) {
        selectedSymptoms.highRisk[0] = symptoms[selectedHighRisk - 1].highRisk[0];
    }
    else {
        // User skipped the selection, return a null-like value
        return Symptoms{}; // Default constructor initializes all strings to empty
    }

    return selectedSymptoms;
}

// Function to get the overseas travel status
string getOverseasTravelStatus() {
    string overseasTravel;
    while (true) {
        cout << "Overseas Travel (Yes/No): ";
        cin >> overseasTravel;
        if (overseasTravel == "Yes" || overseasTravel == "No") {
            break;
        }
        else {
            cout << "Invalid input. Please enter 'Yes' or 'No' for overseas travel status." << endl;
        }
    }
    return overseasTravel;
}

// Function to get the COVID test status
string getCOVIDTestStatus() {
    string covidTestStatus;
    while (true) {
        cout << "COVID Test Status (Positive/Negative): ";
        cin >> covidTestStatus;
        if (covidTestStatus == "Positive" || covidTestStatus == "Negative") {
            break;
        }
        else {
            cout << "Invalid input. Please enter 'Positive' or 'Negative' for COVID Test Status." << endl;
        }
    }
    return covidTestStatus;
}

// Function to get the vital status
string getVitalStatus() {
    string vitalStatus;
    while (true) {
        cout << "Vital Status (Alive/Dead): ";
        cin >> vitalStatus;
        if (vitalStatus == "Alive" || vitalStatus == "Dead") {
            break;
        }
        else {
            cout << "Invalid input. Please enter 'Alive' or 'Dead' for Vital Status." << endl;
        }
    }
    return vitalStatus;
}

// Function to add a new patient and save the data to files
void addPatientAndSaveData(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms) {
    PatientDetails newPatient;
    newPatient.patientID = getUniquePatientID(patients);
    newPatient.name = getPatientName();
    newPatient.dateOfBirth = getPatientDateOfBirth();
    newPatient.address = getPatientAddress();
    newPatient.selectedSymptoms = getSelectedSymptoms(symptoms);
    newPatient.visitedLocation = getVisitedLocation(locations);
    newPatient.overseasTravel = getOverseasTravelStatus();
    newPatient.covidTestStatus = getCOVIDTestStatus();
    newPatient.vitalStatus = getVitalStatus();

    patients.push_back(newPatient);
    cout << "Patient details added successfully." << endl;

    // Save the updated patient details to the file
    writeDataToFile(patients, symptoms, locations, "Patients.txt", "Symptoms.txt", "Locations.txt");
    cout << "Data saved to files.\n" << endl;
}

// Function to recommend COVID test based on patient details
void recommendCOVIDTest(const PatientDetails& patient, const vector<HighRiskLocation>& highRiskLocations) {
    cout << "\nRecommendation for Patient " << patient.patientID << " (" << patient.name << "):" << endl;

    // Check if the patient visited a high-risk location
    bool visitedHighRiskLocation = false;
    for (const HighRiskLocation& location : highRiskLocations) {
        if (patient.visitedLocation == location.locationName) {
            visitedHighRiskLocation = true;
            break;
        }
    }

    // Check if the patient has any symptoms
    bool hasSymptoms = !patient.selectedSymptoms.lowRisk[0].empty() ||
        !patient.selectedSymptoms.lowRisk[1].empty() ||
        !patient.selectedSymptoms.mediumRisk[0].empty() ||
        !patient.selectedSymptoms.mediumRisk[1].empty() ||
        !patient.selectedSymptoms.highRisk[0].empty();

    if (visitedHighRiskLocation && hasSymptoms) {
        cout << "You visited a high-risk location and have symptoms. It is recommended to go for a COVID test." << endl;
    }
    else if (!visitedHighRiskLocation && hasSymptoms) {
        cout << "You did not visit a high-risk location, but you have symptoms. Isolate yourself at home and monitor your health." << endl;
    }
    else {
        cout << "COVID test recommendation may not be necessary, but monitor your health." << endl;
    }

    cout << "-----------------------------------------------------" << endl;
}
