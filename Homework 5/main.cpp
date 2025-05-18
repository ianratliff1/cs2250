#include <iostream>
#include <iomanip>

using namespace std;

double calculateCharges(int, double, double, double);

double calculateCharges(double, double);

bool numIsPositive(double, bool = false);

bool numIsPositive(int, bool = false);

int main() {
    int menuChoice, menuChoiceUpperLimit, menuChoiceLowerLimit, numDaysOfStay;
    double dailyRate, medicationCharges, servicesCharges, total;

    // Display main menu:
    cout << fixed << setprecision(2) << showpoint
            << "****************************************\n"
            << "| 📄 Patient Hospital Bill Calculator  |\n"
            << "****************************************\n"
            << "Choose the patient type:\n"
            << "[1] Inpatient\n"
            << "[2] Outpatient\n"
            << "Enter your choice: ";
    cin >> menuChoice;

    // Validate main menu choice:
    menuChoiceLowerLimit = 1; // lowest menu option (inclusive)
    menuChoiceUpperLimit = 2; // highes menu option (inclusive)
    while (menuChoice < menuChoiceLowerLimit || menuChoice > menuChoiceUpperLimit) {
        cout << "⛔ Selection invalid\n"
                << "Enter your choice: ";
        cin >> menuChoice;
    }

    // Handle menu selection:
    switch (menuChoice) {
        case 1: // inpatient
            cout
                    << "\n--------INPATIENT BILLING--------\n\n"
                    << "Enter the number of days spent in hospital: ";
            do {
                cin >> numDaysOfStay;
            } while (!numIsPositive(numDaysOfStay, true)); // validate that input is not a negative number. Flag true to display warning message.
            cout << "Enter the hospital daily rate: $";

            do {
                cin >> dailyRate;
            } while (!numIsPositive(dailyRate, true)); // validate that input is not a negative number. Flag true to display warning message.

            cout << "Enter the medication charges: $";
            do {
                cin >> medicationCharges;
            } while (!numIsPositive(medicationCharges, true)); // validate that input is not a negative number. Flag true to display warning message.

            cout << "Enter the hospital services (lab tests, etc.) charges: $";
            do {
                cin >> servicesCharges;
            } while (!numIsPositive(servicesCharges, true)); // validate that input is not a negative number. Flag true to display warning message.

            total = calculateCharges(numDaysOfStay, dailyRate, medicationCharges, servicesCharges); // calculate total

            // Display hospital bill:
            cout
                    << endl
                    << "************************************\n"
                    << "|    Inpatient Hospital Bill       |\n"
                    << "|----------------------------------|\n"
                    << "| Length of stay: " << setw(11) << left << numDaysOfStay << "      |\n"
                    << "| Daily rate: $" << setw(11) << dailyRate << "         |\n"
                    << "|----------------------------------|\n"
                    << "| Hospital stay..... $" << setw(11) << right << numDaysOfStay * dailyRate << "  |\n"
                    << "| Medication.........$" << setw(11) << medicationCharges << "  |\n"
                    << "| Hospital services..$" << setw(11) << servicesCharges << "  |\n"
                    << "|----------------------------------|\n"
                    << "|              TOTAL $" << setw(11) << total << "  |\n"
                    << "|**********************************|\n";

            break;

        case 2: // outpatient
            cout << "\n--------OUTPATIENT BILLING--------\n\n";

            cout << "Enter the medication charges: $";
            do {
                cin >> medicationCharges;
            } while (!numIsPositive(medicationCharges, true)); // validate that input is not a negative number. Flag true to display warning message.

            cout << "Enter the hospital services (lab tests, etc.) charges: $";
            do {
                cin >> servicesCharges;
            } while (!numIsPositive(servicesCharges, true)); // validate that input is not a negative number. Flag true to display warning message.

            total = calculateCharges(medicationCharges, servicesCharges);

        // display hospital bill
        cout
                << endl
                << "************************************\n"
                << "|    Outpatient Hospital Bill      |\n"
                << "|----------------------------------|\n"
                << "| Medication.........$" << setw(11) << medicationCharges << "  |\n"
                << "| Hospital services..$" << setw(11) << servicesCharges << "  |\n"
                << "|----------------------------------|\n"
                << "|              TOTAL $" << setw(11) << total << "  |\n"
                << "|**********************************|\n";

            break;

        default: // menu option does not exist
            cout << "⚠️ The program ran into an error and will terminate";
            return 1;
    }
    return 0;
}

/* calculateCharges()
 * Returns (numDaysOfStay * dailyRate) + medicationCharges + servicesCharges
 * Parameters: numDaysOfStay (int), dailyRate (double), medicationCharges (double), servicesCharges (double)
 */
double calculateCharges(int numDaysOfStay, double dailyRate, double medicationCharges, double servicesCharges) {
    return (numDaysOfStay * dailyRate) + medicationCharges + servicesCharges;
}

/* calculateCharges()
 * Sums hospital charges by adding medicationCharges and servicesCharges and returning the sum
 * Parameters: medicationCharges (double), servicesCharges (double)
 */
double calculateCharges(double medicationCharges, double servicesCharges) {
    return medicationCharges + servicesCharges;
}

/* numIsPositive()
 * Tests if a number is positive. If it is, return true. If not, return false
 * Optionally display a warning message if displayMessageIfNegative flag is true
 * Parameters: num (double), displayMessageIfNegative (bool)
 */
bool numIsPositive(double num, bool displayMessageIfNegative) {
    if (num >= 0)
        return true;
    else if (displayMessageIfNegative)
        cout << "⛔ Please enter a positive number: ";
    return false;
}

/* numIsPositive()
 * Tests if a number is positive. If it is, return true. If not, return false
 * Optionally display a warning message if displayMessageIfNegative flag is true
 * Parameters: num (int), displayMessageIfNegative (bool)
 */
bool numIsPositive(int num, bool displayMessageIfNegative) {
    if (num >= 0)
        return true;
    else if (displayMessageIfNegative)
        cout << "⛔ Please enter a positive number: ";
    return false;
}
