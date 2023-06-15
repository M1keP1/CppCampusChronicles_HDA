// Mihir Kumar Patel .....





//"https://en.cppreference.com/w/cpp/io/manip

#include <iostream>
#include <iomanip>

int main() {


    const int size = 10;

    for(int i=1;i <= size; i++) {   //Row

        for (int j = 0; j <= size; j++)    //
        {
            int result = i * j;
            std::cout << std::setw(3) << std::setfill('0') << result << " ";
        }
        std::cout << std::endl;


    }

    return 0;
}