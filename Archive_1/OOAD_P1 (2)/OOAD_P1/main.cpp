#include <iostream>
#include "Calculator.h"
#include <string>
using namespace std;



void Calculator(string x){
    class Calculator calculator;

    // Define variables to be used in the expression
    calculator.define("pi", 3.1415);
    calculator.define("r", 4);

    // Define and compute an expression using the defined variables

    cout<<"Calculator Inintialized"<<endl;
    try {
        double result = calculator.computeValue(x);
        cout << "Result: " << result << endl; // Expected output: 25.132
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

}
int main() {
    string expression = "2*pi*r";
    Calculator(expression);

    return 0;
}
