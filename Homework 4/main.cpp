#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() {
    ifstream inputFile;

    string filename, name, front, back;

    cout << "📋 Front and Back of Line\n";
    cout << "Reads a text file and indicates the first and last names when ordered alphabetically.\n\n";
    cout << "Enter the filename (don't forget the extension!) or enter 'stop' to cancel\n📄 > ";
    cin >> filename;
    if (filename == "stop") {
        return 0;
    }
    inputFile.open(filename);
    while (!inputFile) {
        cout << "⚠️ Error opening file '" << filename << "'\n";
        cout << "Enter the filename (don't forget the extension!) or enter 'stop' to cancel\n📄 > ";
        cin >> filename;
        if (filename == "stop") {
            return 0;
        }
        inputFile.open(filename);
    }
    inputFile >> name;
    front = back = name;

    while (inputFile >> name) {
        if (name < front)
            front = name;
        else if (name > back)
            back = name;
    }
    inputFile.close();
    if (front != "") {
        cout << "Front: " << front << endl;
        cout << "Back: " << back << endl;
    } else {
        cout << "⚠️ Error reading '" << filename << "' or file is empty.\n";
    }

    return 0;
}