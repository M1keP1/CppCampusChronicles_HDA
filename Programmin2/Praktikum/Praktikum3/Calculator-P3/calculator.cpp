#include "calculator.h"
#include "ui_calculator.h"
#include <QDebug>
#include <stdexcept>

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Calculator) {
    ui->setupUi(this);

    // Connect clear button
    connect(ui->pushButton, &QPushButton::clicked, this, &Calculator::clearDisplay); // 'C'

    // Connect equals button
    connect(ui->pushButton_17, &QPushButton::clicked, this, &Calculator::evaluateExpression); // '='

    // Connect all number and operator buttons
    QList<QPushButton*> buttons = {
        ui->pushButton_8, ui->pushButton_7, ui->pushButton_6, ui->pushButton_5,
        ui->pushButton_4, ui->pushButton_3, ui->pushButton_2, ui->pushButton_16,
        ui->pushButton_15, ui->pushButton_14, ui->pushButton_12, ui->pushButton_11,
        ui->pushButton_10, ui->pushButton_13, ui->pushButton_18, ui->pushButton_9,
        ui->pushButton_20, ui->pushButton_3
    };

    for (QPushButton* button : buttons) {
        connect(button, &QPushButton::clicked, this, &Calculator::appendToExpression);
    }
}

Calculator::~Calculator() {
    delete ui;
}

void Calculator::appendToExpression() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString currentText = ui->label->text();
    if (currentText == "0") currentText.clear(); // Replace initial zero

    // Überprüfe, ob der Operator bereits am Ende des Textes steht
    if (button->text() == "/" || button->text() == "*" || button->text() == "+" || button->text() == "-") {
        if (currentText.isEmpty()) {
            return; // Verhindere, dass ein Operator am Anfang eingegeben wird
        }
        if (currentText.endsWith("/") || currentText.endsWith("*") || currentText.endsWith("+") || currentText.endsWith("-")) {
            return; // Verhindere, dass auf einen Operator ein weiterer Operator folgt
        }
    }

    ui->label->setText(currentText + button->text());
}

void Calculator::clearDisplay() {
    ui->label->setText("0");
}

void Calculator::evaluateExpression() {

    QString expr = ui->label->text();
    try {
        int index = 0;
        double result = ausdruck(expr, index);        // Evaluate the expression
        // Sicherstellen, dass der gesamte Ausdruck verarbeitet wurde
       /* if (index < expr.size()) {
            throw std::runtime_error("Ungültiger Ausdruck!");
        }*/
        ui->label->setText(QString::number(result));
    } catch (const std::exception& e) {
        ui->label->setText("Error");
    }
}

// Parser functions
double Calculator::ausdruck(const QString& expr, int& index) {
    double result;
    if (expr[index] == '-') {
        index++;
        result = -summand(expr, index);
    } else {
        if (expr[index] == '+') index++;
        result = summand(expr, index);
    }

    while (index < expr.size() && (expr[index] == '+' || expr[index] == '-')) {
        if (expr[index] == '+') {
            index++;
            result += summand(expr, index);
        } else {
            index++;
            result -= summand(expr, index);
        }
    }
    return result;
}

double Calculator::summand(const QString& expr, int& index) {
    double result = factor(expr, index);
    while (index < expr.size() && (expr[index] == '*' || expr[index] == '/')) {
        if (expr[index] == '*') {
            index++;
            result *= factor(expr, index);
        } else {
            index++;
            double divisor = factor(expr, index);
            if (divisor == 0) throw std::runtime_error("Division durch 0!");
            result /= divisor;
        }
    }
    return result;
}

double Calculator::factor(const QString& expr, int& index) {
    double result;
    if (expr[index] == '(') {
        index++;
        result = ausdruck(expr, index);
        if (index >= expr.size() || expr[index] != ')')
            throw std::runtime_error("Fehlende schließende Klammer!");
        index++;
    } else {
        result = zahl(expr, index);
    }
    return result;
}

double Calculator::zahl(const QString& expr, int& index) {

    double result = 0.0;
    while (index < expr.size() && expr[index].isDigit()) {
        result = result * 10 + (expr[index].unicode() - '0');
        index++;
    }
    if (index < expr.size() && expr[index] == '.') {
        index++;
        double fraction = 1.0;
        while (index < expr.size() && expr[index].isDigit()) {
            fraction *= 0.1;
            result += (expr[index].unicode() - '0') * fraction;
            index++;
        }
    }
    return result;

}


