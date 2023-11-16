#include "data.h"

// ----------------- Task 1.1: Input Sample Data ----------------- //
// Add sample patient data
void addPatientData(vector<PatientDetails>& patients) {
    PatientDetails p1 = { 1, "John Doe", 1990, "1 Main St", {"Fever", "Cough"}, "Melbourne", "Yes", "Negative", "Alive" };
    PatientDetails p2 = { 2, "Jane Doe", 1990, "2 High St", {"Fatigue", "Loss of taste or smell"}, "Sydney", "No", "Positive", "Dead" };
    PatientDetails p3 = { 3, "Harry Potter", 1978, "3 Elm St", {"Fever", "Cough"}, "Brisbane", "Yes", "Negative", "Alive" };
    PatientDetails p4 = { 4, "Hermione Granger", 1982, "4 Oak St", {"Fatigue", "Loss of taste or smell"}, "Perth", "No", "Positive", "Dead" };
    PatientDetails p5 = { 5, "Ronald Weasley", 1995, "5 Birch St", {"Shortness of breath"}, "Adelaide", "Yes", "Positive", "Alive" };
    PatientDetails p6 = { 6, "Voldemort", 1972, "6 Pine St", {"Fever", "Cough"}, "Darwin", "Yes", "Negative", "Alive" };
    PatientDetails p7 = { 7, "Percy Jackson", 1988, "7 Maple St", {"Shortness of breath"}, "Hobart", "No", "Negative", "Alive" };
    PatientDetails p8 = { 8, "David Miller", 1980, "8 Cedar St", {"Fatigue", "Loss of taste or smell"}, "Canberra", "Yes", "Positive", "Dead" };
    PatientDetails p9 = { 9, "Sophia Davis", 1992, "9 Poplar St", {"Fever", "Cough"}, "Adelaide", "Yes", "Negative", "Alive" };
    PatientDetails p10 = { 10, "Oliver Wilson", 1987, "10 Redwood St", {"Shortness of breath"}, "Brisbane", "No", "Positive", "Dead" };
    PatientDetails p11 = { 11, "Alice Johnson", 1993, "11 Douglas St", {"Shortness of breath"}, "Perth", "No", "Positive", "Alive" };
    PatientDetails p12 = { 12, "Bob Smith", 1975, "12 Ash St", {"Fatigue", "Loss of taste or smell"}, "Hobart", "No", "Negative", "Alive" };
    PatientDetails p13 = { 13, "Eva Williams", 1989, "13 Balsa St", {"Shortness of breath"}, "Melbourne", "Yes", "Positive", "Dead" };
    PatientDetails p14 = { 14, "Michael Brown", 1995, "14 Walnut St", {"Fever", "Cough"}, "Sydney", "Yes", "Negative", "Alive" };
    PatientDetails p15 = { 15, "Sophie Johnson", 1993, "15 Alder St", {"Fever", "Cough"}, "Canberra", "No", "Negative", "Alive" };

    patients.push_back(p1);
    patients.push_back(p2);
    patients.push_back(p3);
    patients.push_back(p4);
    patients.push_back(p5);
    patients.push_back(p6);
    patients.push_back(p7);
    patients.push_back(p8);
    patients.push_back(p9);
    patients.push_back(p10);
    patients.push_back(p11);
    patients.push_back(p12);
    patients.push_back(p13);
    patients.push_back(p14);
    patients.push_back(p15);
}

// Add sample symptom data
void addSymptomData(vector<Symptoms>& symptoms) {

	// Define arrays for low, medium, and high-risk symptoms
    Symptoms s1;
    s1.lowRisk[0] = "Fever";
    s1.lowRisk[1] = "Cough";

    s1.mediumRisk[0] = "Fatigue";
    s1.mediumRisk[1] = "Loss of smell";

    s1.highRisk[0] = "Shortness of breath";

    symptoms.push_back(s1);
}


// Add sample location data
void addLocationData(vector<HighRiskLocation>& locations) {
	HighRiskLocation l1 = { "Melbourne Airport" };
	HighRiskLocation l2 = { "Sydney Harbor" };

	locations.push_back(l1);
	locations.push_back(l2);
}