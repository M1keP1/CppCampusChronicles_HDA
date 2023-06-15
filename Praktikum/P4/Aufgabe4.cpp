/*#include <iostream>

void printAddress(const int* variable) {
    std::cout << "Address: " << variable << std::endl;
}

int main() {
    int stackVariable;
    int* heapVariable = new int;

    printAddress(&stackVariable);
    printAddress(heapVariable);

    delete heapVariable;

    return 0;
}
*/


#include <iostream>
#include <new>

int main() {
    try {
        while (true) {
            int* memory = new int[1000000];  // Versuche, 1 Million ints zu reservieren
            std::cout << "Memory allocated: " << memory << std::endl;
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

