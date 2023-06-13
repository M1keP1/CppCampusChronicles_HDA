#include <iostream>

/*
int main() {
    double* pd1 = new double(9.8765);

    std::cout << "Adresse von pd1: " << &pd1 << std::endl;
    std::cout << "Wert von pd1: " << pd1 << std::endl;
    std::cout << "Gleitkommawert, auf den pd1 zeigt: " << *pd1 << std::endl;

    delete pd1;
    pd1 = nullptr;

    return 0;
}

*/



void print_array(std::ostream& os, int* a, int size) {
    for (int i = 0; i < size; i++) {
        os << a[i] << " ";
    }
    os << std::endl;
}

int main() {
    int size = 10; // Anzahl der Elemente im Array
    int* a = new int[size];

    // Werte initialisieren
    for (int i = 0; i < size; i++) {
        a[i] = i + 1;
    }

    // Werte mit print_array ausgeben
    print_array(std::cout, a, size);

    delete[] a;
    a = nullptr;

    return 0;
}
