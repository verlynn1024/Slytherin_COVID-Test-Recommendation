#pragma once

#ifndef FILEIO_H
#define FILEIO_H

#include "data.h"
#include <vector>
#include <string>

using namespace std;

bool writeDataToFile(const vector<PatientDetails>& patients,
    const vector<Symptoms>& symptoms,
    const vector<HighRiskLocation>& locations,
    const string& patientFileName,
    const string& symptomFileName,
    const string& locationFileName);

void displayPatientDetails(const vector<PatientDetails>& patients);

#endif
