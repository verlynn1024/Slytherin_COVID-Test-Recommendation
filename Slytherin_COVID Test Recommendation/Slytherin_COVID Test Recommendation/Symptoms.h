#pragma once
#include "data.h" 
#include "fileIO.h"

#ifndef SYMPTOMS_H
#define SYMPTOMS_H

#include <vector>
#include <string>

using namespace std;

// Function to get selected symptoms from user input
vector<string> getSelectedSymptomsByRiskLevel(const Symptoms& symptoms, int riskLevel);

// Function to display selected symptoms
void displaySelectedSymptoms(const vector<string>& lowRiskSymptoms, const vector<string>& mediumRiskSymptoms, const vector<string>& highRiskSymptoms);

#endif // SYMPTOMS_H
