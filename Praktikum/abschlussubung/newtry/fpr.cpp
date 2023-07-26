#include <iostream>
#include <string>
#include <vector>
#include "fpt.h"

using std::string;
using namespace std;


Liwanze::Liwanze(): name{"noname"}, loc{Region::ndef}{}

std::string Liwanze::get_name() const {return name;}

Liwanze::Region Liwanze::get_loc() const { return loc;}

void Liwanze::print() 
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Location: ";
    switch (loc)
    {
    case Region::ndef:
        std::cout << "Not defined";
        break;
    case Region::amer:
        std::cout << "America";
        break;
    case Region::apac:
        std::cout << "Asia-Pacific";
        break;
    case Region::emea:
        std::cout << "EMEA (Europe, Middle East, and Africa)";
        break;
    }
    std::cout << std::endl;
}

bool Liwanze::connects(string connectsto)
{
    for(const auto& ct: connects_to)
    {
        if (connectsto == ct){return true;}
    }
    return false;
}

bool Liwanze::connected(string connectsfrom)
{
    for(const auto& cf: connects_from)
    {
        if (connectsfrom == cf){return true;}
    }
    return false;
}


bool Liwanze::addconn_to(string to)
{
    if (connects(to)== false){connects_to.push_back(to);return true;}

    return false;
}

bool Liwanze::addconn_from(string from)
{
    if(connected(from)== false){connects_from.push_back(from);return true;}

    return false;
}

void make_conn(string x,string y,vector<Liwanze> &vL)
{
    int xi{0};
    int yi{0};
    int ct{1};

    for (const auto& z : vL)
    {
        if (x==z.get_name()){xi=ct;}
        if (y==z.get_name()){yi=ct;}
        ct++;
    }

    vL.at(xi).addconn_to(vL.at(yi).get_name());
    vL.at(yi).addconn_from(vL.at(xi).get_name());

}
    
void Liwanze::init_connections(vector<Liwanze>&vL)
{
    make_connection("DeeDee", "Sheena", vl);
    make_connection("Joey", "DeeDee", vl);
    make_connection("Joey", "Johnny", vl);
    make_connection("Joey", "Sheena", vl);
    make_connection("Joey", "Suzy", vl);
    make_connection("Suzy", "Joey", vl);
    make_connection("Sheena", "Joey", vl);
    make_connection("Suzy", "Sheena", vl);
    
}

void print_connections(std::vector<Liwanze> vl)
{
    for (int i{0}; i < vl.size(); i++)
    {

        std::cout << "Der Nutzer: " << vl.at(i).get_name() << " hat folgende Connections: \n";
        vl.at(i).print_tierone();
        std::cout << std::endl;
        std::cout << "--------------------------------";
        std::cout << std::endl;
    }
}



void Liwanze::print_tierone()
{

    int connectionsto{0};
    int connectionsfrom{0};
    std::cout << " Das Mitglieg: " << get_name() << " hat folgende Connections: " << std::endl;
    for (unsigned int i{0}; i < connects_to.size(); i++)
    {
        std::cout << " Connected to ";
        std::cout << connects_to.at(i) << std::endl;
        connectionsto++;
    }
    std::cout << connectionsto << " Connctions to in total" << std::endl;
    std::cout << std::endl;
    for (unsigned int i{0}; i < connects_from.size(); i++)
    {
        std::cout << " Connected from ";
        std::cout << connects_from.at(i) << std::endl;
        connectionsfrom++;
    }
    std::cout << connectionsfrom << " Connctions from in total" << std::endl;

    std::cout << std::endl;
    std::cout << "--------------------------------";
    std::cout << std::endl;
}

/*
void add_connection()
{
string input{};
string input2{};
string name{};
bool isregistered1{false};
bool isregistered2{false};
bool isregio{false};
int name1{};
	int name2{};

std::vector<Liwanze> vl2{};
	while (true) {
		isregio = false;
		std::cout << "Geben sie einen Namen ein" << std::endl;
		std::cin >> name;
		
		if (name == "q" || name == "Q")
		{

			break;
		}
		std::cout << "Geben sie eine Region ein" << std::endl;
		std::cin >> input;
		
		if (input == "q" || input == "Q")
		{

			break;
		}
		for (int i{}; i < regio.size(); i++) {
			if (input == regio.at(i))
			{
				isregio = true;
			}
		}
		if (isregio == false) {
			std::cout << "Bitte geben sie eine gueltige Region ein" << std::endl;
			continue;
		}
		vl2.push_back(name, Liwanze::Region{}, {}, {});

	}
while (true) {
		std::cout << "Geben sie zwei Namen für eine verbindung  ein" << std::endl;
		std::cin >> input;
		
		if (input == "q" || input == "Q")
		{
			break;
		}
		std::cin >> input2;
		
		if (input2 == "q" || input2 == "Q")
		{
			break;
		}
		for (unsigned int i{ 0 }; i < vl2.size(); i++) {
			if (input == vl2.at(i).get_name())
			{
				isregistered1 = true;
				break;
			}

		}
		for (unsigned int i{ 0 }; i < vl2.size(); i++) {
			if (input2 == vl2.at(i).get_name())
			{
				isregistered2 = true;
				break;
			}

		}
		if (isregistered1 == false || isregistered2 == false)
		{
			std::cout << "Bitt geben sie einen regestrieten Wert ein" << std::endl;
			isregistered1 = true;
			isregistered2 = true;
			continue;
		}
		if (input == input2)
		{
			std::cout << "Bitte geben nich die gleiche Namen ein" << std::endl;
			continue;
		}


		for (unsigned int i{ 0 }; i < vl2.size(); i++) {
			if (input == vl2.at(i).get_name())
			{
				name1 = i;
			}

			if (input2 == vl2.at(i).get_name())
			{
				name2 = i;
			}
		}
		if (vl2.at(name1).connects(vl2.at(name2).get_name()) || vl2.at(name2).connected(vl2.at(name1).get_name())) {
			std::cout << "Bitte geben nicht schon eine bestehende connection ein" << std::endl;

			continue;
		}
		make_connection(input, input2, vl2);
		std::cout << std::endl << "Sie haben eine neue Verbindung erstellt" << std::endl;
		vl2.at(name1).print_tierone();
		std::cout << std::endl;
		vl2.at(name2).print_tierone();

	}


}
*/



