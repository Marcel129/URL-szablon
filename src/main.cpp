#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "LZespolona.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"
using namespace std;

int main()
{
     UkladRownanLiniowych<LZespolona, ROZ> U;
     UkladRownanLiniowych<double, ROZ> U2;

     cout << "Test szablonu dla macierzy: " << endl;
     cin >> U;
     cin >> U2;
     U.Oblicz();
     U2.Oblicz();
     cout << U <<"Błąd obliczeń wynosi: "<<U.Blad()<<endl<< U2<<"Błąd obliczeń wynosi: "<<U2.Blad()<<endl;
}