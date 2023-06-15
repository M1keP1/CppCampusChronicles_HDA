#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <string>

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}

    void check() {
        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
            throw std::invalid_argument("Invalid date.");
        }

        if (month == 2) {
            if (isLeapYear(year)) {
                if (day > 29) {
                    throw std::invalid_argument("Invalid date: February has 29 days in a leap year.");
                }
            } else {
                if (day > 28) {
                    throw std::invalid_argument("Invalid date: February has 28 days in a non-leap year.");
                }
            }
        } else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day > 30) {
                throw std::invalid_argument("Invalid date: April, June, September, and November have 30 days.");
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date) {
        std::string monthText;
        switch (date.month) {
            case 1:
                monthText = "Jan";
                break;
            case 2:
                monthText = "Feb";
                break;
            case 3:
                monthText = "Mar";
                break;
            case 4:
                monthText = "Apr";
                break;
            case 5:
                monthText = "May";
                break;
            case 6:
                monthText = "Jun";
                break;
            case 7:
                monthText = "Jul";
                break;
            case 8:
                monthText = "Aug";
                break;
            case 9:
                monthText = "Sep";
                break;
            case 10:
                monthText = "Oct";
                break;
            case 11:
                monthText = "Nov";
                break;
            case 12:
                monthText = "Dec";
                break;
            default:
                monthText = "Invalid";
                break;
        }

        os << std::setfill('0') << std::setw(4) << date.year << "-" << monthText << "-"
           << std::setw(2) << date.day;

        return os;
    }
};

int main() {
    try {
        Date date(6, 12, 2011);
        date.check();
        std::cout << date << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
