// OOAD Praktikum 1
//Shrey Sethi 1123132
//Mihir kumar Patel 1123669
#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;


class Token {
public:
    // Enum to identify the type of token
    enum Type { NUMBER, OPERATOR, VARIABLE, LEFT_PAREN, RIGHT_PAREN };


    Type type;
    double value;
    char op;
    string varName;

    // Constructors for different token types
    Token(double val);
    Token(char operation);
    Token(Type t, const string& name);
    Token(Type t);

    // Method to check if the token is an operator
    bool isOperator() const;

    // Method to return operator precedence level (strength) for evaluation
    int strength() const;
};

#endif // TOKEN_H
