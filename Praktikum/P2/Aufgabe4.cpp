#include <iostream>
#include <algorithm> 
using namespace std;

int main() {
    const int n = 9; // Anzahl der Temperaturen
    int temp[n] = { 23, 17, 18, 14, 22, 20, 19, 21 , 24}; // Temperaturwerte
    
    

    sort(temp, temp + n);
    cout << "Sortierte Temperaturwerte: ";


    for (int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;

    
    // Median berechnen
    int median{0};
    if (n % 2 == 0) {
        int middle1 = n/2 - 1;
        int middle2 = n/2;
        cout << "Die mittleren Werte sind: " << temp[middle1] << " und " << temp[middle2] << endl;
        median = (temp[middle1] + temp[middle2]) / 2;
    } else {
        median = temp[n/2];
        cout << "Der Median der Temperaturwerte ist: " << median << endl;
    }
    
    
    
    
    return 0;
}
