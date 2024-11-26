#include <iostream>
#include "Calculator.h"

using namespace std;

int main() {
    Calculator calculator;

    // Define variables to be used in the expression
    calculator.define("pi", 3.1415);
    calculator.define("r", 4);

    // Define and compute an expression using the defined variables
    string expression = "2*pi*r";
    try {
        double result = calculator.computeValue(expression);
        cout << "Result: " << result << endl; // Expected output: 25.132
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}

