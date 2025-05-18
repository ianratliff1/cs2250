// CS2250 Homework 2 - T4 2025
// Student: Ian Ratliff

#include <iostream>
// #include <random> // uncomment to use method 1
#include <iomanip>
#include <ctime>

using namespace std;

int main() {
    // Prepare random integers and answer
    const int MIN = 50;
    const int MAX = 450;

    // Random number generation method 1 (book: random_device):
    // random_device engine;
    // uniform_int_distribution<int> rand(MIN,MAX);
    // const int OPERAND1 = rand(engine);
    // const int OPERAND2 = rand(engine);

    // Random number generation method 2 (seed time):
    unsigned seed = time(0); // get system time
    srand(seed);
    const int OPERAND1 = (rand() % (MAX - MIN + 1)) + MIN;
    const int OPERAND2 = (rand() % (MAX - MIN + 1)) + MIN;

    // Determine answer
    const int ANS = OPERAND1 + OPERAND2;

    // Display program
    cout << "🧮 MATH TUTOR APPLICATION" << endl << endl;
    cout << setw(5) << OPERAND1 << endl;
    cout << "+" << setw(4) << OPERAND2 << endl;
    cout << "-----" << endl;
    cout << setw(6) << "❓" << endl;
    cout << "Work out the problem on your own." << endl;
    cout << "🙋 When you're ready, Press [Enter] to reveal the answer" << endl;
    cin.get();
    cout << "Solution:" << endl;
    cout << setw(5) << OPERAND1 << endl;
    cout << "+" << setw(4) << OPERAND2 << endl;
    cout << "-----" << endl;
    cout << setw(5) << ANS << endl;

    return 0;
}