#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include "Token.h"

using namespace std;


class Calculator {
private:
    unordered_map<string, double> variables; // Map to store defined variables and their values

public:
    // Method to define a variable (assign a name and value)
    void define(const string& name, double value);

    // Method to compute the value of an expression string with variables
    double computeValue(const string& expression);

private:
    // Tokenize the input expression string into a list of tokens
    vector<Token> createTokenList(const string& expression);

    // Evaluate the tokenized expression and return the computed result
    double evaluate(const vector<Token>& tokens);

    // Helper function to apply an operator to values in the stack
    void applyOperator(stack<Token>& operators, stack<double>& values);
};

#endif // CALCULATOR_H

