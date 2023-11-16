// patient.h
#include "data.h" 
#include "location.h"

#ifndef PATIENT_H
#define PATIENT_H

#include <vector> 
#include <string>

using namespace std;

// Function declarations
int getUniquePatientID(const vector<PatientDetails>& patients);
string getPatientName();
int getPatientDateOfBirth();
string getPatientAddress();
string getVisitedLocation(const vector<HighRiskLocation>& locations);
Symptoms getSelectedSymptoms(const vector<Symptoms>& symptoms);
string getOverseasTravelStatus();
string getCOVIDTestStatus();
string getVitalStatus();

void addPatientAndSaveData(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms);
void recommendCOVIDTest(const PatientDetails& patient, const vector<HighRiskLocation>& highRiskLocations);


#endif // PATIENT_H