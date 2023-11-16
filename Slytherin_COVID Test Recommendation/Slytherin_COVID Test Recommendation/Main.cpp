#include "menu.h"
#include "data.h"
#include "fileIO.h"
#include <iostream>

using namespace std;

int main() {
    // Initialize data structures
    vector<PatientDetails> patients;
    vector<Symptoms> symptoms;
    vector<HighRiskLocation> locations;

    // Populate sample data
    addPatientData(patients);
    addSymptomData(symptoms);
    addLocationData(locations);

    // Write data to files
    writeDataToFile(patients, symptoms, locations, "Patients.txt", "Symptoms.txt", "Locations.txt");

    // Run the main menu
    runMainMenu(patients, locations, symptoms);

    return 0;
}
