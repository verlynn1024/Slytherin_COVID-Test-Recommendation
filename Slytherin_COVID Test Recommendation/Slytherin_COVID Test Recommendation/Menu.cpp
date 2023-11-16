#include "menu.h"
#include <iostream>
#include <algorithm>


using namespace std;
vector<Symptoms> symptoms;

void enterPatientDetails(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms)
{
    PatientDetails newPatient;

    // Ask user to input patient ID
    newPatient.patientID = getUniquePatientID(patients);

    // Ask user to input name
    newPatient.name = getPatientName();

    // Ask user to input date of birth
    newPatient.dateOfBirth = getPatientDateOfBirth();

    // Ask user to input address
    newPatient.address = getPatientAddress();

    // Display high-risk locations and ask the user to select
    newPatient.visitedLocation = getVisitedLocation(locations);

    // Display symptoms and ask the user to select
    newPatient.selectedSymptoms = getSelectedSymptoms(symptoms);

    // Ask user about overseas travel
    newPatient.overseasTravel = getOverseasTravelStatus();

    // Ask user about COVID test status
    newPatient.covidTestStatus = getCOVIDTestStatus();

    // Ask user about vital status
    newPatient.vitalStatus = getVitalStatus();

    // Save the new patient details
    patients.push_back(newPatient);

    // Provide COVID test recommendation based on entered details
    recommendCOVIDTest(newPatient, locations);

    // Save the updated patient details to the file
    writeDataToFile(patients, vector<Symptoms>{newPatient.selectedSymptoms}, locations, "Patients.txt", "Symptoms.txt", "Locations.txt");
    cout << "Data saved to files.\n" << endl;
}

//Lamda Expression
void submitCovidTestStatus(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations) 
{
    int patientID;
    string testStatus;

    cout << "Enter Patient ID: ";
    cin >> patientID;

    cout << "Enter Covid Test Status (Positive/Negative): ";
    cin >> testStatus;

    // Find the patient in the vector
    auto it = find_if(patients.begin(), patients.end(), [patientID](const PatientDetails& patient) {
        return patient.patientID == patientID;
        });

    // Check if the patient is found
    if (it != patients.end()) {
        // Update the test status
        it->covidTestStatus = testStatus;

        // If the test is positive, ask for a new visited location
        if (testStatus == "Positive") {
            cout << "Enter new visited location for the patient: ";
            cin.ignore(); // Ignore the newline character left in the buffer
            getline(cin, it->visitedLocation);

            // Check if the location is in the high-risk locations
            auto locationIt = find_if(locations.begin(), locations.end(), [visitedLocation = it->visitedLocation](const HighRiskLocation& location) {
                return location.locationName == visitedLocation;
                });

            if (locationIt == locations.end()) {
                // Location not found, add it to high-risk locations
                locations.push_back({ it->visitedLocation });
            }
        }

        cout << "Covid test status updated successfully." << endl;
    }
    else {
        cout << "Patient not found." << endl;
    }
}

void displayUpdatedLocations(vector<HighRiskLocation>& locations) {
    displayHighRiskLocations(locations);
}

void updateCovidPatientDetails(vector<PatientDetails>& patients) {
    int patientID;
    string newTestStatus;
    string newVitalStatus;

    // Ask user to input patient ID
    cout << "Enter Patient ID: ";
    cin >> patientID;

    // Find the patient in the database
    auto it = find_if(patients.begin(), patients.end(), [patientID](const PatientDetails& p) {
        return p.patientID == patientID;
        });

    if (it != patients.end() && it->covidTestStatus == "Positive") {
        // Ask user to input new status (Cured/Dead)
        cout << "Enter new test status (Positive/Negative): ";
        cin >> newTestStatus;

        // Update the patient's vital status
        it->covidTestStatus = newTestStatus;

        cout << "Enter new vital status (Alive/Dead): ";
        cin >> newVitalStatus;

        it->vitalStatus = newVitalStatus;

        // Save the updated patient details to the file
        writeDataToFile(patients, vector<Symptoms>{it->selectedSymptoms}, vector<HighRiskLocation>{}, "Patients.txt", "Symptoms.txt", "Locations.txt");
        cout << "Patient details updated successfully.\n";
    }
    else {
        cout << "Patient not found or not COVID positive in the database.\n";
    }
}

void displayCovidPositivePatientDetails(const vector<PatientDetails>& patients)
{

    cout << "COVID Positive Patients Details:\n";

    for (const PatientDetails& patient : patients) {
        if (patient.covidTestStatus == "Positive") {
            // Display details for COVID positive patients
            cout << "Patient ID: " << patient.patientID << "\n";
            cout << "Name: " << patient.name << "\n";
            cout << "Date of Birth: " << patient.dateOfBirth << "\n";
            cout << "Address: " << patient.address << "\n";
            cout << "Visited Location: " << patient.visitedLocation << "\n";

            // Display selected symptoms
            cout << "Symptoms:\n";
            cout << "Low Risk: " << patient.selectedSymptoms.lowRisk[0] << ", " << patient.selectedSymptoms.lowRisk[1] << "\n";
            cout << "Medium Risk : " << patient.selectedSymptoms.mediumRisk[0] << ", " << patient.selectedSymptoms.mediumRisk[1] << "\n";
            cout << "High Risk: " << patient.selectedSymptoms.highRisk[0] << "\n";

            cout << "Overseas Travel: " << patient.overseasTravel << "\n";
            cout << "COVID Test Status: " << patient.covidTestStatus << "\n";
            cout << "Vital Status: " << patient.vitalStatus << "\n";

            cout << "------------------------\n";
        }
    }
}

void runMainMenu(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms){
    
    int choice;

    do {
        cout << "COVID Test Recommendation System" << endl;
        cout << "1- Enter your details for COVID-Test Recommendation" << endl;
        cout << "2- Submit Your Covid test status & Update the Location database" << endl;
        cout << "3- Display the Updated Location (High Risk for COVID)" << endl;
        cout << "4- Update COVID Patient Details" << endl;
        cout << "5- Display the COVID Positive Patient Details" << endl;
        cout << "6- Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            enterPatientDetails(patients, locations, symptoms);
            break;
        case 2:
            submitCovidTestStatus(patients, locations);
            break;
        case 3:
            displayUpdatedLocations(locations);
            //changes made here
            addLocation(locations);
            writeDataToFile(patients, symptoms, locations, "Patients.txt", "Symptoms.txt", "Locations.txt");
            break;
        case 4:
            updateCovidPatientDetails(patients);
            break;
        case 5:
            displayCovidPositivePatientDetails(patients);
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n" << endl;
        }

    } while (choice != 6);
}
