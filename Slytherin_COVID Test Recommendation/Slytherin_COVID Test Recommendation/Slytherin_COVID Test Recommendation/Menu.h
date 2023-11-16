#pragma once
using namespace std;

#ifndef MENU_H
#define MENU_H

#include "data.h"
#include "fileIO.h"
#include "patient.h"
#include "location.h"
#include <vector>

	extern vector<Symptoms> symptoms;

	void enterPatientDetails(vector<PatientDetails>& patients, vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms);

	//void submitCovidTestStatus(vector<PatientDetails>& patients,vector<HighRiskLocation>& locations);

	//void displayUpdatedLocations(const vector<HighRiskLocation>& locations);

	//void updateCovidPatientDetails(vector<PatientDetails>& patients);

	//void displayCovidPositivePatientDetails(const vector<PatientDetails>& patients);

	void runMainMenu(vector<PatientDetails>& patients,vector<HighRiskLocation>& locations, vector<Symptoms>& symptoms);

#endif
