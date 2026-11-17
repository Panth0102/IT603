
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string filename, line;
    ifstream file;

    // Take file name from the user
    cout << "Enter file name/path: ";
    getline(cin, filename);

    // Open the file
    file.open(filename);

    // Check whether the file opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    int lineCount = 0, wordCount = 0, charCount = 0;

    cout << "\nFile Contents:\n";
    cout << "--------------------------\n";

    // Read and display the file line by line
    while (getline(file, line)) {
        lineCount++;

        cout << lineCount << ". " << line << endl;

        // Count characters
        charCount += line.length();

        // Count words in the current line
        stringstream ss(line);
        string word;

        while (ss >> word) {
            wordCount++;
        }
    }

    // Close the file
    file.close();

    // Display total counts
    cout << "\n--------------------------\n";
    cout << "Total Lines      : " << lineCount << endl;
    cout << "Total Words      : " << wordCount << endl;
    cout << "Total Characters : " << charCount << endl;

    return 0;
}
