#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Name_values
{
public:
    Name_values() {} // Default constructor

    Name_values(const std::string &n, const std::vector<int> &v)
        : name(n), values(v) {} // Constructor

    void add_value(const int &value)
    {
        values.push_back(value); // Add value to the vector
    }

    void print_all() const
    {
        std::cout << name << ": ";
        for (int value : values)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    std::string get_name() const
    {
        return name;
    }

private:
    std::string name;
    std::vector<int> values;
};

// Helper function to convert a weekday string to its abbreviated form
std::string getAbbreviatedWeekday(const std::string &weekday)
{
    if (weekday == "Montag")
        return "Mo";
    else if (weekday == "Dienstag")
        return "Di";
    else if (weekday == "Mittwoch")
        return "Mi";
    else if (weekday == "Donnerstag")
        return "Do";
    else if (weekday == "Freitag")
        return "Fr";
    else if (weekday == "Samstag")
        return "Sa";
    else if (weekday == "Sonntag")
        return "So";
    else
        return "";
}

int main()
{
    std::vector<std::string> weekdays = {"Mo", "Di", "Mi", "Do", "Fr", "Sa", "So"};
    std::vector<Name_values> week(7); // Container for weekdays and their values
    int rejectedCount = 0;            // Count of rejected values

    std::cout << "Enter weekday-value pairs (e.g., Montag 42 Dienstag 77) or 'q' to quit:" << std::endl;

    std::string weekday;
    int value;

    while (std::cin >> weekday)
    {
        // Convert the weekday to its abbreviated form
        weekday = getAbbreviatedWeekday(weekday);

        // Check if the weekday is valid
        if (weekday == "q")
            break;

        // Check if the input is a valid weekday
        if (weekday.empty())
        {
            std::cin.clear();
            std::string input;
            std::cin >> input; // Read and discard the invalid input
            rejectedCount++;
            continue;
        }

        // Read the value
        if (!(std::cin >> value))
        {
            std::cin.clear();
            std::string input;
            std::cin >> input; // Read and discard the invalid input
            rejectedCount++;
            continue;
        }

        // Find the index of the weekday
        auto it = std::find(weekdays.begin(), weekdays.end(), weekday);
        if (it != weekdays.end())
        {
            // Store the value in the corresponding weekday container
            int index = std::distance(weekdays.begin(), it);
            week[index].add_value(value);
        }
        else
        {
            rejectedCount++;
        }
    }

    std::cout << "Value lists for each weekday:" << std::endl;
    std::cout << std::fixed << std::setprecision(2); // Set the precision for average value output

    // Iterate over each weekday and output its value list
}