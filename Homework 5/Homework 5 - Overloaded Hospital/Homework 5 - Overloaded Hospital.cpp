// Homework 5 - Overloaded Hospital.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

double calculateCharges(int, double, double, double);
double calculateCharges(double, double);
bool numIsPositive(double);
bool numIsPositive(int);

int main()
{
    int menuChoice;
    int menuChoiceUpperLimit;
    int menuChoiceLowerLimit;

    cout << "📄 Patient Hospital Bill Calculator\n"
        << "-----------------------------------\n"
        << "Choose the patient type:\n"
        << "[1] Inpatient\n"
        << "[2] Outpatient\n"
        << "Enter your choice: ";
    cin >> menuChoice;
    menuChoiceLowerLimit = 1;
    menuChoiceUpperLimit = 2;
    
    while (menuChoice < menuChoiceLowerLimit || menuChoice > menuChoiceUpperLimit) {
        cout << "⛔ Selection invalid\n"
            << "Enter your choice: ";
        cin >> menuChoice;
    }
}

double calculateCharges(int numDaysOfStay, double dailyRate, double medicationCharges, double servicesCharges)
{
    return (numDaysOfStay * dailyRate) + medicationCharges + servicesCharges;
}

double calculateCharges(double medicationCharges, double servicesCharges)
{
    return 0.0;
}

bool numIsPositive(double)
{
    return false;
}

bool numIsPositive(int)
{
    return false;
}


