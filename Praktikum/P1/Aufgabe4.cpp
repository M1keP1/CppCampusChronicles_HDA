#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "Smallest int value: " << numeric_limits<int>::min() << endl;
    cout << "Largest int value: " << numeric_limits<int>::max() << endl;
    cout << "Smallest long int value: " << numeric_limits<long int>::min() << endl;
    cout << "Largest long int value: " << numeric_limits<long int>::max() << endl;
    return 0;
}
