// Mihir Kumar Patel
//Praktikum 4 PG1 Aufgabe 1

#include <iostream>
#include <stdexcept>
using namespace std;



class Token {
private:
    char kind;
    int value;

public:
    Token(char ch) : kind(ch), value(0) {}
    Token(char ch, int val) : kind(ch), value(val) {}

    char getKind() const {
        return kind;
    }

    int getValue() const {
        return value;
    }
};

void myerror(const std::string& message) {          //definign function myerror to throw runtime exceptions
    throw std::runtime_error(message);
}

/* int calculate(int x, int y, char op) {              //defining function calculate to calculate the operations and also check specific false operations
    switch (op) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            if (y == 0)
                myerror("Division by zero");                //division by zero
            return x / y;
        default:
            myerror("Unknown operator");
    }
}

int main() {
    int x = 0, y = 0;
    char op = '\0';

    std::cout << "Rechenausdruck mit +, -, *, / (Ende mit ;) > ";
    while (std::cin >> x >> op && op != ';') {
        if (!std::cin) {
            myerror("Input error");
        }
        if (std::cin >> y) {
            try {
                x = calculate(x, y, op);
            } catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                return 1;
            }
        } else {
            myerror("Invalid input");
        }
    }

    std::cout << "Ergebnis: " << x << std::endl;
    return 0;
}
*/

Token getToken() {
    char ch;
    std::cin >> ch;

    switch (ch) {   
                                        //every possible input that is accepted
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case ';':
            return Token(ch);
        case '.':
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6': 
        case '7': 
        case '8': 
        case '9': 

        {
            std::cin.putback(ch);
            double val;
            std::cin >> val;
            return Token('8', val);
        }

        case '?':
            std::cout << "Hilfe:" << std::endl;
            std::cout << "- Geben Sie mathematische Ausdrücke ein." << std::endl;
            std::cout << "- Verwenden Sie + für Addition, - für Subtraktion, * für Multiplikation, / für Division." << std::endl;
            std::cout << "- Verwenden Sie ( und ) für Klammern, um die Reihenfolge der Operationen festzulegen." << std::endl;
            std::cout << "- Beenden Sie die Eingabe mit ;" << std::endl;
            break;


        default:
            myerror("Unerwartetes Token");
    }

    return Token('\0');  // Dummy return to suppress warning, should never be reached
}

int expression();

int primary() {
    Token t = getToken();
    switch (t.getKind()) {
        case '(': {
            int result = expression();
            t = getToken();
            if (t.getKind() != ')')
                myerror("')' erwartet");
            return result;
        }
        case '8':
            return t.getValue();
        case '-':
            return -primary();
        case '+':
            return primary();
        default:
            myerror("Primärausdruck erwartet");
    }

    return 0;  // Dummy return to suppress warning, should never be reached
}

int term() {
    int left = primary();
    Token t = getToken();

    while (true) {
        switch (t.getKind()) {
            case '*':
                left *= primary();
                t = getToken();
                break;
            case '/': {
                int divisor = primary();
                if (divisor == 0)
                    myerror("Division durch Null");
                left /= divisor;
                t = getToken();
                break;
            }
            default:
                std::cin.putback(t.getKind());
                return left;
        }
    }
}

int expression() {
    int left = term();
    Token t = getToken();

    while (true) {
        switch (t.getKind()) {
            case '+':
                left += term();
                t = getToken();
                break;
            case '-':
                left -= term();
                t = getToken();
                break;
            default:
                std::cin.putback(t.getKind());
                return left;
        }
    }
}

void testCalculator(int x, const string& expression, int expected)
{
    int result = x;
    char op = ' ';
    int y = 0;

    istringstream iss(expression);

    while (iss >> op >> y)
    {
        result = calculateExpression(result, op, y);
    }

    if (result == expected)
        cout << "PASS: " << expression << " = " << expected << endl;
    else
        cout << "FAIL: " << expression << " expected " << expected << ", but got " << result << endl;
}

int main() {
    try {
        std::cout << "Rechenausdruck mit +, -, *, / (Ende mit ;) > ";
        while (std::cin) {
            Token t = getToken();
            if (t.getKind() == ';')
                break;
            std::cout << "Ergebnis: " << expression() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
}
}