#include <iostream>

using namespace std;

int main()

{
    cout<<"The bluetooth device has been connected!" << endl;

    string inp{};
    int key{};
    cout << "Enter word to be encrypted" <<endl;
    cin >>  inp;
    cout << "Enter key" << endl;
    cin >> key;


    for(char &alp:inp)
    {
        alp = static_cast<int>(alp+key);
    }
    cout<<"Encrypted Word---"<< inp <<endl;


    return 0;
}

//fertig
