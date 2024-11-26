#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class Calculator;
}
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

private slots:
    void appendToExpression();
    void clearDisplay();
    void evaluateExpression();

    void on_pushButton_11_clicked();

private:
    Ui::Calculator *ui;

    // Parser functions
    double ausdruck(const QString& expr, int& index);
    double summand(const QString& expr, int& index);
    double factor(const QString& expr, int& index);
    double zahl(const QString& expr, int& index);
};
#endif // CALCULATOR_H
