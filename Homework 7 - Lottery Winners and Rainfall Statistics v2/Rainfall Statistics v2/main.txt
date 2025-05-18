#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void selectionSort(double [], string [], int);

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
        cout << "Enter inches of rainfall for " << months[i] << ": ";
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
    cout << "\nRainfall Statistics:\n"
        << "--------------------------\n"
        << "Total rainfall: " << totalRainfall << endl
        << "Average rainfall: " << averageRainfall << endl
        << "Least rainfall in: " << months[lowestRainfallIndex] << endl
        << "Most rainfall in: " << months[highestRainfallIndex] << endl;

    // New in v2: Show months sorted by rainfall amount
    selectionSort(rainfallAmounts, months, NUM_MONTHS);

    cout
        << "\nMonths by rainfall amount, in descending order ↓\n"
        << "----------------------------------------------------\n"
        << setw(6) << left << "💦 ";
    for (int i=0; i < NUM_MONTHS; i++) {
        cout << months[i] << " (" << rainfallAmounts[i] << "\")" << endl;
        if (i < 10)
            cout << setw(6) << left << "↓";
        else if (i == 10)
            cout << setw(6) << left << "💧";
        else
            cout << "\n";
    }

    return 0;
}

void selectionSort(double rainfallAmounts[], string months[], const int NUM_MONTHS) {
    int maxIndex, maxValue;
    for (int start = 0; start < (NUM_MONTHS - 1); start++) {
        maxIndex = start;
        maxValue = rainfallAmounts[start];
        for (int i = start + 1; i < NUM_MONTHS; i++) {
            if (rainfallAmounts[i] > maxValue) {
                maxValue = rainfallAmounts[i];
                maxIndex = i;
            }
        }
        swap(rainfallAmounts[start], rainfallAmounts[maxIndex]);
        swap(months[start], months[maxIndex]);
    }
}