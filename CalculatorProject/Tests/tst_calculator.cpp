#include "../Calculator.h"
#include <QTest>

class CalculatorTest : public QObject {
    Q_OBJECT

private slots:
    void defineVariables();
    void computeExpressions();
    void invalidExpression();
};

void CalculatorTest::defineVariables()
{
    Calculator calculator;
    calculator.define("pi", 3.1415);
    calculator.define("radius", 5);

    QCOMPARE(calculator.computeValue("pi"), 3.1415);
    QCOMPARE(calculator.computeValue("radius"), 5.0);
}

void CalculatorTest::computeExpressions()
{
    Calculator calculator;
    calculator.define("pi", 3.1415);
    calculator.define("r", 4);

    QCOMPARE(calculator.computeValue("2 * pi * r"), 25.132); // 2πr = 25.132
}


QTEST_MAIN(CalculatorTest)

#include "tst_calculator.moc"
