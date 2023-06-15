#include <iostream>
using namespace std;

int main(){

/*
 string name;
 cout << "Enter Your name Please! : " << endl ;
 cin >> name;   //getline(cin,name) ;

 int jahr;
 cout << "Please enter your Geburtsjahr : ";
 cin >> jahr;

 cout << name << "_" << jahr;
*/
//double yfb{0.0}, total{0.0}, month{0.0}, jahrealt{0.0} ,monate{0.0};
double yfb, total, month, jahrealt,monate;
cout << "Birth Year" << endl;
cin >> yfb;

  
  cout << "birth month " << endl;
  cin >> month;
  if(month<=4.0){
    jahrealt =2023-yfb;
    monate = (4-month)*1/12;
    }
  else{

  
    jahrealt=2023-yfb-1;
    monate = (12+4-month)*1/12;


  }
  total =jahrealt +monate;
  cout <<"Er ist schon " << total << "alt" << endl;
  return 0;


}