#include "symptoms.h"
#include <iostream>
#include <sstream>

using namespace std;

// Function to get selected symptoms by risk level
// Modify the getSelectedSymptomsByRiskLevel function in your original code

vector<string> getSelectedSymptomsByRiskLevel(const Symptoms& symptoms, int riskLevel) {
    vector<string> selectedSymptoms;

    // Display filtered symptoms
    cout << "\nPlease select ";
    switch (riskLevel) {
    case 0:
        cout << "low-risk symptoms :";
        for (int i = 0; i < 2; ++i) {
            cout << " " << i + 1 << ". " << symptoms.lowRisk[i];
            if (i < 1) {
                cout << ",";
            }
        }
        cin.ignore();
        break;
    case 1:
        cout << "medium-risk symptoms :";
        for (int i = 0; i < 2; ++i) {
            cout << " " << i + 3 << ". " << symptoms.mediumRisk[i];
            if (i < 1) {
                cout << ",";
            }
        }
        break;
    case 2:
        cout << "high-risk symptoms :";
        cout << " 5. " << symptoms.highRisk[0];
        break;
    }
    cout << endl;

    // Get selected symptoms
    string selection;
    cout << "Enter the numbers corresponding to the selected symptoms (comma-separated): ";
    //cin.ignore();
    getline(cin, selection);

    // Check if the selection is not empty
    if (!selection.empty()) {
        // Tokenize the input string
        istringstream iss(selection);
        while (iss) {
            int index;
            if (iss >> index) {
                // Validate the user's selection
                switch (riskLevel) {
                case 0:
                    if (index >= 1 && index <= 2) {
                        selectedSymptoms.push_back(symptoms.lowRisk[index - 1]);
                    }
                    break;
                case 1:
                    if (index >= 3 && index <= 4) {
                        selectedSymptoms.push_back(symptoms.mediumRisk[index - 3]);
                    }
                    break;
                case 2:
                    if (index == 5) {
                        selectedSymptoms.push_back(symptoms.highRisk[0]);
                    }
                    break;
                }
            }
            else {
                break; // Exit the loop if extraction fails
            }

            // Handle the comma separator
            if (iss.peek() == ',') {
                iss.ignore();
            }
        }
    }

    return selectedSymptoms;
}



// Function to display selected symptoms
void displaySelectedSymptoms(const vector<string>& lowRiskSymptoms, const vector<string>& mediumRiskSymptoms, const vector<string>& highRiskSymptoms) {
    cout << "\nAll Selected Symptoms:" << endl;

    cout << "Low Risk Symptoms:" << endl;
    if (!lowRiskSymptoms.empty()) {
        for (const string& symptom : lowRiskSymptoms) {
            cout << symptom << endl;
        }
    }
    else {
        cout << "None" << endl;
    }

    cout << "Medium Risk Symptoms:" << endl;
    if (!mediumRiskSymptoms.empty()) {
        for (const string& symptom : mediumRiskSymptoms) {
            cout << symptom << endl;
        }
    }
    else {
        cout << "None" << endl;
    }

    cout << "High Risk Symptoms:" << endl;
    if (!highRiskSymptoms.empty()) {
        for (const string& symptom : highRiskSymptoms) {
            cout << symptom << endl;
        }
    }
    else {
        cout << "None" << endl;
    }
}
