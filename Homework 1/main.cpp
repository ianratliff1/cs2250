// CS2250 Homework 1 - T4 2025
// Student: Ian Ratliff

#include <iostream>

using namespace std;

int main()
{
    const float TOWN_MPG = 23.5, HWY_MPG = 28.9;
    const int FUEL_TANK_CAPACITY_GAL = 20;
    const float POSSIBLE_TRAVEL_DISTANCE_HWY = FUEL_TANK_CAPACITY_GAL * HWY_MPG;
    const float POSSIBLE_TRAVEL_DISTANCE_TOWN = FUEL_TANK_CAPACITY_GAL * TOWN_MPG;

    cout << "Your car has a " << FUEL_TANK_CAPACITY_GAL << " gallon gas tank." << endl;
    cout << "Based on your car's fuel mileage specifications..." << endl;
    cout << "🛣️ You can drive up to " << POSSIBLE_TRAVEL_DISTANCE_HWY << " miles for highway driving." << endl;
    cout << "🏙️ You can drive up to " << POSSIBLE_TRAVEL_DISTANCE_TOWN << " miles for town driving." << endl;

    return 0;
}