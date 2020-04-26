#include <iostream>
#include "Wektor.cpp"
#include "LZespolona.hh"
using namespace std;
#define ROZMIAR 3


int main(void)
{
    Wektor<LZespolona,ROZMIAR> wek1,wek2;
    cout<<"Test szablonu wektora z zadanym typem LZespolona:"<<endl;
    cin>>wek1>>wek2;
    cout<<"Wektor 1: "<<wek1<<"Wektor 2: "<<wek2
    <<"Podwojony pierwszy wektor: "<<wek1*2
    <<"Suma wektorów: "<<wek1+wek2<<"Różnica wektorów: "<<wek1-wek2<<"Moduł trzeciego elementu pierwszego wektora: "<<wek1[2].modul()
    <<endl<<"Sprzezenie drugiego elementu drugiego wektora: "<<wek2[1].sprzezenie()<<endl<<endl;

    Wektor<double,ROZMIAR> wek3,wek4;
    cout<<"Test szablonu wektora z zadanym typem double:"<<endl;
    cin>>wek3>>wek4;
    cout<<"Wektor 1: "<<wek3<<"Wektor 2: "<<wek4<<"Podwojony pierwszy wektor: "<<wek3*2
    <<"Suma wektorów: "<<wek3+wek4<<"Różnica wektorów: "<<wek3-wek4<<endl;
}