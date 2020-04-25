#include <iostream>
#include "Wektor.hh"
#include "LZespolona.hh"
using namespace std;
#define ROZMIAR 3


int main(void)
{
    Wektor<LZespolona,3> wek1,wek2;
    cout<<"Test szablonu wektora z zadanym typem LZespolona:"<<endl;
    cin>>wek1>>wek2;
    cout<<"Wektor 1: "<<wek1<<"Wektor 2: "<<wek2
    <<"Suma wektorów: "<<wek1+wek2<<"Różnica wektorów: "<<wek1-wek2<<"Moduł trzeciego elementu pierwszego wektora: "<<wek1[2].modul()
    <<endl<<"Sprzezenie drugiego elementu drugiego wektora: "<<wek2[1].sprzezenie()<<endl;
}