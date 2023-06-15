#include <iostream>
#include <stdexcept>

int main() {
    

    double yfb, total, month, jahrealt, monate;
    std::cout << "Birth Year: ";
    std::cin >> yfb;

    try {

        if (std::cin.fail()) {
            throw std::runtime_error("Birth Year must be a number.");
        }

        std::cout << "Birth Month: ";
        std::cin >> month;

        if (std::cin.fail()) {
            throw std::runtime_error("Invalid input. Birth Month must be a number.");
        }

        if (month <= 4.0) {
            jahrealt = 2023 - yfb;
            monate = (4 - month) * 1 / 12;
        }
        else {
            jahrealt = 2023 - yfb - 1;
            monate = (12 + 4 - month) * 1 / 12;
        }

        total = jahrealt + monate;
        std::cout << "Er ist schon " << total << " Jahre alt" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
