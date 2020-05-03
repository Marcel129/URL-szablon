#include <iostream>
#include <fstream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "LZespolona.hh"
#include "UkladRownanLiniowych.hh"
#include "rozmiar.h"
using namespace std;

int main(int argc, char **argv)
{
     if (argc < 2)
     {
          cout << "Nie podano opcji wywołania programu" << endl;
          exit(1);
     }
     if (*argv[1] == 'r')
     {
          fstream dane;
          dane.open("rzeczywiste.txt", ios::in);
          if (dane.good() == true)
          {
               UkladRownanLiniowych<double, ROZ> U;
               dane >> U;
               U.Oblicz();
               cout << U << "Błąd obliczeń wynosi: " << U.Blad() << "\nWektor błędu to: " << U.wektor_bledu() << endl;
          }
     }
     else if (*argv[1] == 'z')
     {
          fstream dane;
          dane.open("zespolone.txt", ios::in);
          if (dane.good() == true)
          {
               UkladRownanLiniowych<LZespolona, ROZ> U2;
               cout << "Test szablonu dla macierzy: " << endl;
               dane >> U2;
               U2.Oblicz();
               cout << U2 << "Błąd obliczeń wynosi: " << U2.Blad()
                    << "\nWektor błędu to: " << U2.wektor_bledu() << endl;
          }
     }
     else
     {
          cout << "Nie rozpoznano opcji" << endl;
          exit(1);
     };
}