#include <iostream>
#include <stdexcept>
#include <sstream>

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

void myerror(const std::string& message) {
    throw std::runtime_error(message);
}

Token getToken() {
    char ch;
    std::cin >> ch;

    switch (ch) {
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
        case '9': {
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

    return Token('\0');
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

    return 0;
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
        switch (op) {
            case '+':
                result += y;
                break;
            case '-':
                result -= y;
                break;
            case '*':
                result *= y;
                break;
            case '/':
                if (y != 0)
                    result /= y;
                else
                    throw runtime_error("Division by zero!");
                break;
            default:
                throw runtime_error("Unknown operator!");
        }
    }

    if (result == expected)
        cout << "PASS: " << expression << " = " << expected << endl;
    else
        cout << "FAIL: " << expression << " expected " << expected << ", but got " << result << endl;
}

int main() {
    try {
        // Test cases
        testCalculator(0, "2 * 3 + 4", 10);
        testCalculator(10, "10 - 5 * 2", 0);
        testCalculator(8, "8 / 2 - 1", 3);
        testCalculator(4, "4 / 0", -1); // Expected to throw an exception
        testCalculator(3, "3 ^ 2", -1); // Expected to throw an exception
    } catch (const std::exception& e) {
        std::cerr << "Fehler: " << e.what() << std::endl;
    }

    return 0;
}
