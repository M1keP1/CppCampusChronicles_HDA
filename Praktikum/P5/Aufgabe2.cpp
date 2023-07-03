#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Forward declaration of the class kunde
class kunde;

// Class auftrag representing an order
class auftrag
{
public:
    // Constructor taking an id as a parameter
    auftrag(const string &s) : id{s}, pk{nullptr} {}

    // Print function to display the order details
    void print() const;

    // Getter for the order id
    string get_id() const { return id; }

    // Setter to associate a customer with the order
    void set_kunde(kunde *);

    // Getter to retrieve the associated customer
    kunde *get_kunde() const;

private:
    string id;       // Order id
    kunde *pk;       // Pointer to the associated customer
};

// Class kunde representing a customer
class kunde
{
public:
    // Constructor taking a name as a parameter
    kunde(const string &s) : name{s}, vpa{} {}

    // Print function to display the customer details and associated orders
    void print() const;

    // Getter for the customer name
    string get_name() const { return name; }

    // Function to add an order to the customer
    void add_auftrag(auftrag *);

    // Getter to retrieve all the associated orders
    vector<auftrag *> get_auftrage() const;

private:
    std::string name;                // Customer name
    std::vector<auftrag *> vpa;      // Vector to store associated orders
};

// Implementation of the print function for the auftrag class
void auftrag::print() const
{
    std::cout << "auftrag: " << id << endl;
}

// Setter function to associate a customer with the order
void auftrag::set_kunde(kunde *kunde1)
{
    pk = kunde1;
}

// Getter function to retrieve the associated customer
kunde *auftrag::get_kunde() const
{
    return pk;
}

// Implementation of the print function for the kunde class
void kunde::print() const
{
    cout << "Kunde: " << name << endl;
    cout << "Aufträge: " << endl;
    for (const auto &auftrag : vpa)
    {
        auftrag->print();
    }
}

// Function to add an order to the customer
void kunde::add_auftrag(auftrag *auftrag1)
{
    vpa.push_back(auftrag1);
    auftrag1->set_kunde(this);
}

// Getter function to retrieve all the associated orders
vector<auftrag *> kunde::get_auftrage() const
{
    return vpa;
}

// Function to run the test scenario
void run_test()
{
    // Dynamically allocate a kunde object
    kunde *k1 = new kunde{"Sepplhuber-Finsterwalder"};

    // Create a kunde object
    kunde k2{"Kurz"};

    // Dynamically allocate auftrag objects
    auftrag *a1 = new auftrag{"Decke streichen"};
    auftrag *a2 = new auftrag{"Wand tapezieren"};

    // Create auftrag objects without dynamic allocation
    auftrag a3{"Jalousie montieren"};
    auftrag a4{"Laminat verlegen"};

    // Associate the orders with the customer
    k1->add_auftrag(a1);
    k1->add_auftrag(a2);
    k1->add_auftrag(&a3);

    // Associate an order with a different customer
    a4.set_kunde(&k2);

    // Print customer and order details
    k1->print();
    k2.print();
    a1->print();
    a2->print();
    a3.print();
    a4.print();

    // Deallocate dynamically allocated objects
    delete k1;
    delete a1;
    delete a2;
}

// Main function
int main()
{
    run_test();
    return 0;
}
