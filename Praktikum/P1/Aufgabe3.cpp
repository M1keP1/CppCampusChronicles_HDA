#include <iostream>
using namespace std;

int sub(int a,int b){ 
    return a + b;
}

void print_sub(int a,int b){
    cout << a << " + " << b << " = " << sub(a,b) << endl;
}

string cite(string l){
    cout << " \" " << l << " \" " << endl;
    return 0;
}


int main(){
    int a,b;
    /*cout << "Enter Two Numbers" << endl;
    cin >> a >> b;
    print_sub(a,b);*/
    cite("Hello there");
    return 0;
    
}