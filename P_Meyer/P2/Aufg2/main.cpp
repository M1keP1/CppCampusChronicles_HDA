#include <iostream>

using namespace std;

int main()
{
    cout << "the bluetooth device has been connected!" << endl;
    int n;
    int g{};
    int l{INT32_MAX};
    int s{};

    while(cout <<"Enter"&&cin>>n)
        {

        if(n==0||n<0){
                break;
            }
        if(n>g){
                g=n;
            }
        if(n<l){
                l=n;
        }
        s+=n;
        }
    cout<<"Here are your results"<<endl;
    cout<<"Biggest---"<<g<<endl;
    cout<<"smallest---"<<l<<endl;
    cout<<"sum---"<<s<<endl;

    return 0;
}


//fertig
