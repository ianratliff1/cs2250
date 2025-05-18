#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    int userChoice;
    double amtTime;
    double amtDistance;
    const int AIR_FPS = 1100;
    const int WATER_FPS = 4900;
    const int STEEL_FPS = 16400;

    cout << setprecision(4) << fixed << showpoint;
    cout << "The Speed of Sound" << endl;
    cout << "----------------------------" << endl;
    cout << "To determine the amount of time it will take for sound to propagate, choose the medium it is traveling through..." << endl;
    cout << "1. 💨 Air" << endl;
    cout << "2. 🌊 Water" << endl;
    cout << "3. ⛓️ Steel" << endl;
    cout << "Enter your choice: ";
    cin >> userChoice;

    switch (userChoice) {
        case 1:
            cout << endl << "Enter the distance, in feet, the sound wave will travel through air: ";
            cin >> amtDistance;
            if (amtDistance > 0) {
                amtTime = amtDistance / AIR_FPS;
                cout << "A sound wave takes " << amtTime << " seconds to travel " << amtDistance << " feet through air." << endl;
            } else { cout << "You have entered an invalid distance. Exiting."; }
            break;
        case 2:
            cout << endl << "Enter the distance, in feet, the sound wave will travel through water: ";
        cin >> amtDistance;
        if (amtDistance > 0) {
            amtTime = amtDistance / WATER_FPS;
            cout << "A sound wave takes " << amtTime << " seconds to travel " << amtDistance << " feet through water." << endl;
        } else { cout << "You have entered an invalid distance. Exiting."; }
        break;
        case 3:
            cout << endl << "Enter the distance, in feet, the sound wave will travel through steel: ";
        cin >> amtDistance;
        if (amtDistance > 0) {
            amtTime = amtDistance / STEEL_FPS;
            cout << "A sound wave takes " << amtTime << " seconds to travel " << amtDistance << " feet through steel." << endl;
        } else { cout << "You have entered an invalid distance. Exiting."; }
        break;
        default:
            cout << "Invalid selection. Exiting." << endl;
    }







    return 0;
}