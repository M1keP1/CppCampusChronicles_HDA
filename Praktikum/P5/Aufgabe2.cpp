#include <iostream>
#include <vector>
#include <string>

using namespace std;
class kunde;

class auftrag
{
public:
    auftrag(const string &s) : id{s}, pk{nullptr} {}
    void print() const;
    string get_id() const { return id; }
    void set_kunde(kunde *);
    kunde *get_kunde() const;

private:
    string id;
    kunde *pk;
};

class kunde
{
public:
    kunde(const string &s) : name{s}, vpa{} {}
    void print() const;
    string get_name() const { return name; }
    void add_auftrag(auftrag *);
    std::vector<auftrag *> get_auftrage() const;

private:
    std::string name;
    std::vector<auftrag *> vpa;
};
void auftrag::print() const
{
    std::cout << "auftrag :" << id << endl;
}
void auftrag::set_kunde(kunde *kunde1)
{
    pk = kunde1;
}
kunde *auftrag::get_kunde() const
{
    return pk;
}
void kunde::print() const
{
    cout << "Kunde: " << name << endl;
    cout << "Aufträge: " << endl;
    for (const auto &auftrag : vpa)
    {
        auftrag->print();
    }
}
void kunde::add_auftrag(auftrag *auftrag1)
{
    vpa.push_back(auftrag1);
    auftrag1->set_kunde(this);
}
vector<auftrag *> kunde::get_auftrage() const
{
    return vpa;
}
void run_test()
{
    kunde *k1{new kunde{"Sepplhuber-Finsterwalder"}};
    kunde k2{"Kurz"};
    auftrag *a1{new auftrag{"Decke streichen"}};
    auftrag *a2{new auftrag{"Wand tapezieren"}};
    auftrag a3{"Jalousie montieren"};
    auftrag a4{"Laminat verlegen"};

    k1->add_auftrag(a1);
    k1->add_auftrag(a2);
    k1->add_auftrag(&a3);

    a4.set_kunde(&k2);

    k1->print();
    k2.print();
    a1->print();
    a2->print();
    a3.print();
    a4.print();

    delete k1;
    delete a1;
    delete a2;
}

int main()
{
    run_test();
    return 0;
}
