
#include "Token.h"


Token::Token(double val) : type(NUMBER), value(val), op('\0') {}


Token::Token(char operation) : type(OPERATOR), value(0), op(operation) {}


Token::Token(Type t, const string& name) : type(t), varName(name), value(0), op('\0') {}


Token::Token(Type t) : type(t), value(0), op('\0') {}


bool Token::isOperator() const {
    return type == OPERATOR;
}

// Return the precedence (strength) of operators for evaluation
int Token::strength() const {
    if (op == '*' || op == '/') return 2; // Multiplication and Division have higher precedence
    if (op == '+' || op == '-') return 1; // Addition and Subtraction have lower precedence
    return 0;                             // Other tokens have no precedence
}

