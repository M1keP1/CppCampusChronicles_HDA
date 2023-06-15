#include <iostream>
using namespace std;

int main() {

    int ix, iy, iz;
    
    // Benutzer auffordern, drei ganze Zahlen einzugeben

    cout << "Geben Sie eine Zahl zwischen 0 und 999 ein: ";
    cin >> ix;
    cout << "Geben Sie eine weitere Zahl zwischen 0 und 999 ein: ";
    cin >> iy;
    cout << "Geben Sie noch eine weitere Zahl zwischen 0 und 999 ein: ";
    cin >> iz;

    /*
    
    int arr[] = { ix, iy, iz };
    sort(arr, arr + 3);
    cout << "Die Zahlen in aufsteigender Reihenfolge: ";
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    
    */
    


    // Summe und Produkt berechnen 

    int sum = ix + iy + iz;
    int prod = ix * iy * iz;
    cout << "Summe: " << sum << endl;
    cout << "Produkt: " << prod << endl;
    


    // Differenzen berechnen 

    int diff1 = ix - iy;
    int diff2 = iy - iz;
    cout <<  ix << " - " << iy << ": " << diff1 << endl;
    cout <<  iy << " - " << iz << ": " << diff2 << endl;
    


    // Quotienten berechnen 

    float quot1 = static_cast<float>(ix) / iy;
    float quot2 = static_cast<float>(iy) / iz;
    cout << "Quotient von " << ix << " und " << iy << ": " << quot1 << endl;
    cout << "Quotient von " << iy << " und " << iz << ": " << quot2 << endl;
    
    return 0;
}
