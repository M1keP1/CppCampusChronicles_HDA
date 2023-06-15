#include <iostream>
using namespace std;

int main(){

    int by ,bm;
    cout << "Enter your Birth year and month as numbers" <<endl;
    cin >> by;
    cin >> bm;
      
    double bt = 2023-by ;
    if(bm>4){
        cout << bt;
        
    }
    else{
        cout <<bt-1;
    }





}