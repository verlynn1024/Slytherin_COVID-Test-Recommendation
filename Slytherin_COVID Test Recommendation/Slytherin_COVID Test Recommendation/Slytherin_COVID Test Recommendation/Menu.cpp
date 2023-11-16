#include "menu.h"
#include <iostream>

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
            //submitCovidTestStatus(patients, locations);
            break;
        case 3:
            //displayUpdatedLocations(locations);
            break;
        case 4:
            //updateCovidPatientDetails(patients);
            break;
        case 5:
            //displayCovidPositivePatientDetails(patients);
            break;
        case 6:
            break;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
        }

    } while (choice != 6);
}
