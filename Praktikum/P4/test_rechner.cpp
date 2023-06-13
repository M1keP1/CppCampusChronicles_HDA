#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

// Function to compare floating-point numbers with a tolerance
bool isEqual(double a, double b) {
    return std::fabs(a - b) < 0.000001;
}

// Function to run tests on the Mini-Rechner program
void runMiniCalculatorTests() {
    std::vector<std::string> inputs = {
        "2+3;",
        "10-5;",
        "3*4;",
        "20/5;",
        "(2+3)*4;",
        "-7*3;",
        "2+(-3);",
        "-(-5);",
        "10+(-2*3);",
        "8/0;",
        "1.5+2.7;",
        "2.3*4.5;",
        "-3.14/2;",
        "2.5+(-1.8);",
        "-(5.5+2.5)*3.5;",
        "10.1-(-2.1);",
        "2.7*(-2.5);",
        "10.5/0.5;",
        "(3+4;",
        "ABC+DEF;"
    };

    std::vector<std::string> expectedOutputs = {
        "Ergebnis: 5",
        "Ergebnis: 5",
        "Ergebnis: 12",
        "Ergebnis: 4",
        "Ergebnis: 20",
        "Ergebnis: -21",
        "Ergebnis: -1",
        "Ergebnis: 5",
        "Ergebnis: 4",
        "Fehler: Division durch Null",
        "Ergebnis: 4.2",
        "Ergebnis: 10.35",
        "Ergebnis: -1.57",
        "Ergebnis: 0.7",
        "Ergebnis: -28",
        "Ergebnis: 12.2",
        "Ergebnis: -6.75",
        "Ergebnis: 21",
        "Fehler: ')' erwartet",
        "Fehler: Unerwartetes Token"
    };

    std::cout << "Mini-Rechner Testergebnisse:" << std::endl;

    // Perform the tests
    for (size_t i = 0; i < inputs.size(); i++) {
        std::cout << "Test " << (i + 1) << ":" << std::endl;
        std::cout << "Eingabe: " << inputs[i] << std::endl;
        std::cout << "Erwartete Ausgabe: " << expectedOutputs[i] << std::endl;

        // Redirect input from std::cin
        std::istringstream iss(inputs[i]);
        std::streambuf* previousCinBuffer = std::cin.rdbuf(iss.rdbuf());

        // Redirect output from std::cout
        std::stringstream ss;
        std::streambuf* previousCoutBuffer = std::cout.rdbuf(ss.rdbuf());

        try {
            main();
            std::string actualOutput = ss.str();
            // Remove newline characters from the actual output
            actualOutput.erase(std::remove(actualOutput.begin(), actualOutput.end(), '\n'), actualOutput.end());
            std::cout << "Tatsächliche Ausgabe: " << actualOutput << std::endl;

            // Compare the actual output with the expected output
            if (actualOutput == expectedOutputs[i]) {
                std::cout << "Test erfolgreich!" << std::endl;
            } else {
                std::cout << "Test fehlgeschlagen!" << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Fehler: " << e.what() << std::endl;
        }

        // Restore the original cin and cout buffers
        std::cin.rdbuf(previousCinBuffer);
        std::cout.rdbuf(previousCoutBuffer);

        std::cout << std::endl;
    }
}

int main() {
    runMiniCalculatorTests();
    return 0;
}
