#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stdexcept>

using namespace std;

string getFullWeekday(const string& shortWeekday, const unordered_map<string, string>& corrections) {
    auto it = corrections.find(shortWeekday);
    if (it != corrections.end()) {
        return it->second;
    }
    throw invalid_argument("Invalid weekday or short form. Please try again.");
}

int main() {
    vector<string> weekdays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    vector<vector<int>> values(7); // Vector of vectors to store values for each weekday

    unordered_map<string, string> corrections = {
        {"mo", "Monday"},
        {"di", "Tuesday"},
        {"mi", "Wednesday"},
        {"do", "Thursday"},
        {"fr", "Friday"},
        {"sa", "Saturday"},
        {"so", "Sunday"}
    };

    int incorrectCount = 0; // Counter for incorrect input days

    try {
        string input;
        cout << "Enter weekday-value pairs (e.g., 'Thursday 23 Friday 56'): ";
        while (cin >> input) {
            if (input == "q") {
                break;
            }

            string weekday;
            try {
                weekday = getFullWeekday(input, corrections);
            } catch (const invalid_argument& e) {
                cout << "Invalid weekday. Please try again." << endl;
                ++incorrectCount;
                continue;
            }

            int value;
            cin >> value;

            auto it = find(weekdays.begin(), weekdays.end(), weekday);
            if (it != weekdays.end()) {
                values[distance(weekdays.begin(), it)].push_back(value);
            } else {
                cout << "Invalid weekday. Please try again." << endl;
                ++incorrectCount;
            }
        }

        // Print the collected values for each weekday
        for (size_t i = 0; i < weekdays.size(); ++i) {
            cout << weekdays[i] << ": ";
            for (int value : values[i]) {
                cout << value << " ";
            }
            cout << endl;
        }

        cout << "Incorrect input day count: " << incorrectCount << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}
