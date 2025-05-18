// Homework 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int NUM_MONTHS = 12;
    double rainfallAmounts[12];
    int highestRainfallIndex = 0, lowestRainfallIndex = 0;
    double totalRainfall = 0, averageRainfall = 0, highestRainfall, lowestRainfall;

    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "Rainfall Statistics\n"
        << "-----------------------------\n";
    // Input the rainfall amount for all of the months:
    for (int i = 0; i < NUM_MONTHS; i++) {
        cout << "Enter rainfall for " << months[i] << ": ";
        cin >> rainfallAmounts[i];
        while (rainfallAmounts[i] < 0) {
            cout << "[!] Please enter a positive number." << endl
                << "Enter rainfall for " << months[i] << ": ";
            cin >> rainfallAmounts[i];
        }
        
    }
    
    // Loop through rainFallAmounts[] and sum for the total amount as well as determine high and low limits:
    for (int i = 0; i < NUM_MONTHS; i++) {
        totalRainfall += rainfallAmounts[i];
        if (rainfallAmounts[i] >= rainfallAmounts[highestRainfallIndex])
            highestRainfallIndex = i;
        if (rainfallAmounts[i] <= rainfallAmounts[lowestRainfallIndex])
            lowestRainfallIndex = i;
    }

    // Determine average rainfall amount:
    averageRainfall = totalRainfall / NUM_MONTHS;

    // Display statistics
    cout << "Total rainfall: " << totalRainfall << endl
        << "Average rainfall: " << averageRainfall << endl
        << "Least rainfall in: " << months[lowestRainfallIndex] << endl
        << "Most rainfall in: " << months[highestRainfallIndex] << endl;
    
    return 0;
}