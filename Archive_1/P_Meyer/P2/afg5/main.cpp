#include <iostream>

using namespace std;

void display()
{
    cout <<"Herzlich Willkommen zum Flächenberechner!"<<endl;
            cout << "Von welcher geometrischen Figur soll die Fläche berechnet werden?"<<endl;

                    cout <<"k) Kreis"<<endl;
    cout <<"r) Rechteck"<<endl;
    cout <<"d) Dreieck"<<endl;
    cout <<"q) Beenden"<<endl;

}

int main()
{


    char choice{};

        display();

        // Take user input
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Process the user's choice
        switch (choice) {
        case 'k':
            std::cout << "You selected Option k." << std::endl;

            break;

        case 'r':
            std::cout << "You selected Option r." << std::endl;

            break;

        case 'd':
            std::cout << "You selected Option d." << std::endl;

            break;

        case 'q':
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            display();
        }


    return 0;


}
