#include <iostream>
#include <string>
class employee
{

public:
    employee();
    employee(std::string na, int de, double sa);
    virtual void print() const;
    static void print_list();

private:
    std::string name;
    int department;
    double salary;
    employee *next;
    static employee *list;
};
employee::employee() : employee("", 0, 0.0)
{
    // Default constructor implementation
}

employee::employee(std::string na, int de, double sa) : name{na}, department{de}, salary{sa}, next(list)
{
    list = this;
}
employee *employee::list(nullptr);
void employee::print_list()
{
    for (employee *p{list}; p != nullptr; p = p->next)
    {
        p->print();
        std::cout << std::endl;
    }
}
void employee::print() const
{
    std::cout << "Name: " << name << ", Department: " << department << ", Salary: " << salary;
}
class manager : public employee
{
public:
    manager();
    manager(std::string, int, double, int, employee *);
    void print() const;

private:
    int level;
    employee *deputy;
};
manager::manager() : employee(), level(0), deputy(nullptr)
{
    // Default constructor implementation for manager
}

manager::manager(std::string nn, int dd, double sa, int lev, employee *dpy) : employee{nn, dd, sa}, level{lev}, deputy{dpy}
{ /*...*/
}
void manager::print() const
{
    employee::print();
    std::cout << ", Level: " << level;
}
int main()
{

    employee e1("vedant", 1, 3000.3);
    employee e2;
    employee e3;

    manager m1("vedant", 1, 3000.3, 2, &e1);
    manager m2("vedu", 2, 4000.3, 2, &e2);
    manager m3("ved", 2, 34000.3, 2, &e3);
    employee::print_list();

    return 0;
}
