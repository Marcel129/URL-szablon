#ifndef MACIERZ_HH
#define MACIERZ_HH
#include <iostream>
#include "rozmiar.h"
#include "Wektor.hh"
#include "LZespolona.hh"

template <typename TYP, int ROZMIAR>
class Macierz
{
  Wektor<TYP,ROZMIAR> tablica[ROZMIAR];

public:
  Macierz(){};
  Macierz(Wektor<TYP,ROZMIAR> tab[])
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = tab[i];
  };
  Wektor<TYP,ROZMIAR> &operator[](int ind); //set
  const Wektor<TYP,ROZMIAR> &operator[](int ind) const; //get

  Wektor<TYP,ROZMIAR> operator*(const Wektor<TYP,ROZMIAR> W) const; //mnożenie macierzy przez wektor
  void transponuj_macierz(void);
  TYP wyz_gauss();
};

template <typename TYP, int ROZMIAR>
std::istream &operator>>(std::istream &Strm, Macierz<TYP,ROZMIAR> &Mac);
template <typename TYP, int ROZMIAR>
std::ostream &operator<<(std::ostream &Strm, const Macierz<TYP,ROZMIAR> &Mac);

#endif
