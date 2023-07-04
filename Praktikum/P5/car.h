#ifndef CAR_H
#define CAR_H

#include <iostream>
using namespace std;

#include <string> 
using std::string;

const string noname{ "<>" }; // globale Konstante 

class car
{
  
  public:
car();
 explicit car(string);

string get_name() const ;
  car*   get_next() const ;
  car*   get_last() const ;
  
static car* sget_last() ;

virtual void print() const = 0; 


private:
string name;
static car*last;
car*next;

};

class Van : public car //inherit from car
{
    public:
Van();
Van(string , int ,int );
void print() const;
int getdoors() const;
int getmileage()const;


private:
int doors;
int mileage;

};


class sportscar:public car
{
public:
sportscar();
sportscar(string , int );

void print( ) const;
int gethorsepower( )const;
private:
int horsepower;

};

class  suv : public sportscar  //inherit frm sportscar
{ public:
    suv();
    
     suv(string , int ,bool ,int );
     void print ()const;
bool getrooftop()const;
int getcruisevalue()const;
private:
bool rooftop;
int cruisecontrol_at;
};
class Luxurycar : public car 
{
 public:
  Luxurycar() ;
  Luxurycar( string , bool  ) ;
  bool get_bar() const;     
  void print() const; // bleibt virtual 
 private:
  bool has_bar; 
};

class Stretchlimo : public Luxurycar 
{
 public:
  Stretchlimo() ;
  Stretchlimo( string , bool , int ) ;
  void print() const; 
 private:
  int seats; 
};





#endif