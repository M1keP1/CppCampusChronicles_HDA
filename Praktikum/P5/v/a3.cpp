#include <iostream> 
#include <vector>
using namespace std;
class Manager;
class Employee
{
public:
    Employee(string Name, int Department, double Salary): name{Name}, department{Department}, salary{Salary}, next{list} { list = this; }
    Employee() : name{"No_Name"}, department{0}, salary{0} {}
    virtual ~Employee() {}
    virtual void print() const
    {
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
    static void print_list()
    {
        for (Employee *p{list}; p != nullptr; p = p->next)
        {
            p->print();
            cout << std::endl; // zeilenweise } }
        }
        string get_Name()
        {
            return name;
        }
        Employee *get_Next()
        {
            return next;
        }

    protected:
        string name;
        int department;
        double salary;
        Employee *next;
        static Employee *list; // static Attribut (Listenanfang)
    };
    Employee *Employee::list = nullptr;
    class Manager : public Employee
    {
    public:
        Manager(string Name, int Department, double Salary, int Level, Employee *Deputy): Employee(Name, Department, Salary)
        {
            level = Level;
            deputy = Deputy;
        }

        Manager(): Employee()
        {
            level = 0;
            deputy = nullptr;
        }
        void print() const
        {
            cout << "Name: " << name << endl;
            cout << "Department: " << department << endl;
            cout << "Salary: " << salary << endl;
            cout << "Level: " << level << endl;
            cout << "Deputy: " << deputy->get_Name() << endl;
        }

    private:
        int level;
        Employee *deputy;
    };
    int main()
    {
        Employee *list = nullptr;
        Employee worker{"Nelson 'Big Head' Bighetti", 3, 4000};
        Employee worker2{"Elrich Bachman", 1, 3500};
        Employee developer{"Dinesh Chugtai", 3, 5500};
        Employee developer2{"Bertram Gilfoyle", 3, 5500.1};
        Manager CFO("Donald 'Jared' Dunn", 2, 2000, 2, &developer2);
        Manager CEO("Richard Hendricks", 1, 90000, 1, &CFO);
        Employee::print_list();
        // Free memory
        Employee *current = list;
        while (current != nullptr)
        {
            Employee *temp = current;
            current = current->get_Next();
            delete temp;
        }
        // Check if memory was successfully freed 
        if (list == nullptr)
        {

            cout << "Memory has been successfully freed." << endl;
        }
        else
        {
            cout << "Error occurred while freeing memory." << endl;
        }
        return 0;
    }

}
