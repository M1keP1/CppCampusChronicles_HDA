


#include <iostream>
#include <cmath> // Für std::sqrt()
using namespace std;

int main() {
    /*double x;
    cout << "Geben Sie eine Gleitkommaa >= 0 ein: ";
    cin >> x;
    
    if (x < 0) {
        cout << "Die a muss größer oder gleich 0 sein." << endl;
        return 1;
    }
    
    double square_root = sqrt(x);
    cout << "Die QuadratWurzel_old von " << x << " ist " << square_root << endl;*/

    /*

    double a, dWurzelalt , dWurzelneu;
    cout << "Geben Sie eine positive Gleitkommaa ein: ";
    cin >> dWurzelalt;
    a = dWurzelalt;
    dWurzelneu = (dWurzelalt+ (a / dWurzelalt))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    dWurzelneu = (dWurzelneu+ (a / dWurzelneu))/2.0 ;
    
    cout << "Die QuadratWurzel_old von " << a << " ist " << dWurzelneu << endl;
    return 0;

    */
    
    
    

   
    double a{0}, precision{0.1};
    cout << "Geben Sie eine Gleitkommazahl >= 0 ein: ";
    cin >> a;
    cout << "Mindest-Genauigkeit";
    cin >> precision;

    double x = a;
    double xn = (x + a / x) / 2.0;
    cout << xn;
    while (abs(xn - x) >= precision) {
        x = xn;
        xn = (x + a / x) / 2.0;
    }

    cout << "Die QuadratWurzel von " << a << " ist " << xn << endl;
    cout << "Testorakel: " << sqrt(a) << endl;

    return 0;

   
    
    
}
