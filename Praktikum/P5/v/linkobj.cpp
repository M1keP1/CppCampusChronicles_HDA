#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;
    Person* next;

    Person(const std::string& n, int a) : name(n), age(a), next(nullptr) {}
};

class LinkedList {
private:
    Person* head;
public:
    LinkedList() : head(nullptr) {}

    void addPerson(const std::string& name, int age) {
        Person* newPerson = new Person(name, age);
        newPerson->next = head;
        head = newPerson;
        std::cout << "Person added!\n";
    }

    void displayList() {
        std::cout << "List of people:\n";
        Person* current = head;
        while (current != nullptr) {
            std::cout << "Name: " << current->name << ", Age: " << current->age << "\n";
            current = current->next;
        }
    }
};

int main() {
    LinkedList peopleList;

    int numPeople;
    std::cout << "Enter the number of people you want to add: ";
    std::cin >> numPeople;

    for (int i = 0; i < numPeople; ++i) {
        std::string name;
        int age;

        std::cout << "Person " << i + 1 << ":\n";
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cout << "Enter age: ";
        std::cin >> age;

        peopleList.addPerson(name, age);
    }

    // Display the list of people
    peopleList.displayList();

    return 0;
}
