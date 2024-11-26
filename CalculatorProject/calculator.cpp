#include "Calculator.h"
#include <stack>
#include <stdexcept>
#include <cctype>
#include <iostream>

using namespace std;


void Calculator::define(const string& name, double value) {
    variables[name] = value;
}


double Calculator::computeValue(const string& expression) {
    vector<Token> tokens = createTokenList(expression); // Tokenize the expression
    return evaluate(tokens); // Evaluate and return the result
}

// Create a list of tokens from the expression string
vector<Token> Calculator::createTokenList(const string& expression) {
    vector<Token> tokens;
    string numOrVar;

    // Loop through each character in the expression
    for (size_t i = 0; i < expression.size(); ++i) {
        char c = expression[i];
        if (isspace(c)) continue; // Ignore whitespace

        // If the character is part of a number or variable, accumulate it
        if (isdigit(c) || c == '.') {
            numOrVar += c;
        } else if (isalpha(c)) {
            numOrVar += c;
        } else {
            // If a number or variable was accumulated, add it as a token
            if (!numOrVar.empty()) {
                if (isdigit(numOrVar[0]) || numOrVar[0] == '.') {
                    tokens.emplace_back(stod(numOrVar)); // Add as number token
                } else {
                    tokens.emplace_back(Token::VARIABLE, numOrVar); // Add as variable token
                }
                numOrVar.clear();
            }
            // Add operator or parenthesis tokens
            if (c == '(') tokens.emplace_back(Token::LEFT_PAREN);
            else if (c == ')') tokens.emplace_back(Token::RIGHT_PAREN);
            else tokens.emplace_back(c); // For operators like +, -, *, /
        }
    }
    // Add any remaining accumulated token
    if (!numOrVar.empty()) {
        if (isdigit(numOrVar[0]) || numOrVar[0] == '.') {
            tokens.emplace_back(stod(numOrVar));
        } else {
            tokens.emplace_back(Token::VARIABLE, numOrVar);
        }
    }
    return tokens;
}

// Evaluate the tokenized expression and calculate the result
double Calculator::evaluate(const vector<Token>& tokens) {
    stack<double> values;      // Stack to hold values
    stack<Token> operators;    // Stack to hold operators

    for (const auto& token : tokens) {
        if (token.type == Token::NUMBER) {
            values.push(token.value); // Push number onto values stack
        } else if (token.type == Token::VARIABLE) {
            if (variables.find(token.varName) != variables.end()) {
                values.push(variables[token.varName]); // Push variable value onto values stack
            } else {
                throw runtime_error("Undefined variable: " + token.varName);
            }
        } else if (token.type == Token::LEFT_PAREN) {
            operators.push(token); // Push '(' onto operators stack
        } else if (token.type == Token::RIGHT_PAREN) {
            while (!operators.empty() && operators.top().type != Token::LEFT_PAREN) {
                applyOperator(operators, values); // Apply operators until '(' is found
            }
            operators.pop(); // Remove '('
        } else if (token.isOperator()) {
            // Apply operators with higher precedence before pushing the new operator
            while (!operators.empty() && operators.top().isOperator() &&
                   operators.top().strength() >= token.strength()) {
                applyOperator(operators, values);
            }
            operators.push(token);
        }
    }
    // Apply remaining operators
    while (!operators.empty()) {
        applyOperator(operators, values);
    }
    return values.top(); // Return final result
}

// Apply an operator from the operators stack to values from the values stack
void Calculator::applyOperator(stack<Token>& operators, stack<double>& values) {
    double b = values.top(); values.pop();
    double a = values.top(); values.pop();
    Token op = operators.top(); operators.pop();

    double result;
    switch (op.op) {
    case '+': result = a + b; break;
    case '-': result = a - b; break;
    case '*': result = a * b; break;
    case '/': result = a / b; break;
    default: throw runtime_error("Invalid operator");
    }
    values.push(result); // Push result back onto values stack
}

