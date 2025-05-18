#include <iostream>
#include <vector>

using namespace std;

bool searchInVector(vector<int>, int);

int main() {
    vector<int> myLuckyNumbers {13579,
                                26791,
                                26792,
                                33445,
                                55555,
                                62483,
                                77777,
                                79422,
                                85647,
                                93121};
    int thisWeeksNumber = -1;
    bool thisWeeksNumberMatch = false;

    cout << "🎰 Lucky Numbers Lotto Number Test 🎰" << endl;
    while (thisWeeksNumber < 10000 || thisWeeksNumber > 99999) {
        cout << "Enter this week's 5-digit winning lottery number (or 0 to quit): ";
        cin >> thisWeeksNumber;
        if (thisWeeksNumber == 0)
            return 0;
        else if (thisWeeksNumber < 10000 || thisWeeksNumber > 99999)
            cout << "⛔ Enter a valid 5-digit number or 0 to quit\n";
    }

    thisWeeksNumberMatch = searchInVector(myLuckyNumbers, thisWeeksNumber);

    if (thisWeeksNumberMatch)
        cout << "\nRESULT: 🤑 Congratulations! Lottery number \"" << thisWeeksNumber << "\" matches one of the numbers you played!" << endl;
    else
        cout << "\nRESULT: You did not win this week. Better luck next time.\n";





    return 0;
}

bool searchInVector(const vector<int> vectorToSearch, const int searchNumber) {
    bool found = false;
    int index = 0;
    int size = vectorToSearch.size();
    while (index < size && !found) {
        if (vectorToSearch[index] == searchNumber)
            found = true;
        index++;
    }

    return found;
}
