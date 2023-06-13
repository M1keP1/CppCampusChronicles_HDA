#include <iostream>
#include <cstring>

void myvocals(char* cs) {
    while (*cs != '\0') {
        if (*cs == 'a' || *cs == 'e' || *cs == 'i' || *cs == 'o' || *cs == 'u') {
            *cs = '*';
        }
        cs++;
    }
}

char* cstring_copier(const char* str) {
    size_t length = std::strlen(str);
    char* copy = new char[length + 1];
    std::strcpy(copy, str);
    return copy;
}

int main() {
    const char* inputStrings[] = {
        "Hallo",
        "This is a test",
        "Aufgabe3",
        "C++ Programming",
        "Heap Allocation",
        "Null Terminated"
    };

    // Test myvocals function
    std::cout << "myvocals function:" << std::endl;
    for (const char* str : inputStrings) {
        char* copy = cstring_copier(str);
        myvocals(copy);
        std::cout << "Input: " << str << " => Result: " << copy << std::endl;
        delete[] copy;
    }
    std::cout << std::endl;

    // Test cstring_copier function
    std::cout << "cstring_copier function:" << std::endl;
    for (const char* str : inputStrings) {
        char* copy = cstring_copier(str);
        std::cout << "Input: " << str << " => Copy: " << copy << std::endl;
        delete[] copy;
    }

    return 0;
}
