#include <QtTest>
#include "calculator.h"

class calc_tests : public QObject
{
    Q_OBJECT

public:
    calc_tests();
    ~calc_tests();

private slots:
    void test_simpleExpression();
};

calc_tests::calc_tests()
{
    // Constructor logic (if needed)
}

calc_tests::~calc_tests()
{
    // Destructor logic (if needed)
}

// Test a simple arithmetic expression
void calc_tests::test_simpleExpression()
{
    Calculator calculator;
    calculator.define("a", 2);
    calculator.define("b", 3);

    QString expression = "a + b * 2";
    double result = calculator.computeValue(expression.toStdString());

    QCOMPARE(result, 9.0); // 2 + (3 * 2) = 8
}

QTEST_APPLESS_MAIN(calc_tests)

#include "tst_calc_tests.moc"
