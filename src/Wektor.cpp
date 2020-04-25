
#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include "rozmiar.h"
using namespace std;
template <typename TYP, int ROZMIAR>
class Wektor
{
  TYP tablica[ROZMIAR];

public:
  Wektor(){};
  Wektor(TYP moja_tab[])
  {
    for (int i = 0; i < ROZMIAR; i++)
      tablica[i] = moja_tab[i];
  }

  const TYP &operator[](int ind) const; //get
  TYP &operator[](int ind);             //set

  Wektor operator*(const double mnoznik) const;  //mnozenie wektora przez liczbe
  Wektor operator/(const double dzielnik) const; //dzielenie wektora przez liczbe
  Wektor operator+(const Wektor &W2) const;      //dodawanie dwoch wektorow
  Wektor operator-(const Wektor &W2) const;      //odejmowanie dwoch wektorow
};




template <typename TYP, int ROZMIAR>
std::istream &operator>>(std::istream &strWej, Wektor<TYP,ROZMIAR> &W)
{
  for (int i = 0; i < ROZMIAR; i++)
    strWej >> W[i];
  return strWej;
}
template <typename TYP, int ROZMIAR>
std::ostream &operator<<(std::ostream &strWyj, const Wektor<TYP,ROZMIAR> &W)
{
  for (int i = 0; i < ROZMIAR; i++)
  {
    strWyj << std::setw(MIEJSCE) << std::setprecision(PRECYZJA) << W[i];
    if (i + 1 < ROZMIAR)
      strWyj << "\t";
  }
  std::cout << std::endl;
  return strWyj;
}
template <typename TYP, int ROZMIAR>
const TYP &Wektor<TYP, ROZMIAR>::operator[](int ind) const //get
{
  if (ind < 0 || ind > ROZMIAR)
  {
    std::cout << ind << std::endl;
    std::cerr << "Przekroczenie zakresu" << std::endl;
    exit(1);
  }
  return tablica[ind];
}
template <typename TYP, int ROZMIAR>
TYP &Wektor<TYP, ROZMIAR>::operator[](int ind) //set
{
  if (ind < 0 || ind > ROZMIAR)
  {
    std::cout << ind << std::endl;
    std::cerr << "Przekroczenie zakresu" << std::endl;
    exit(1);
  }
  return tablica[ind];
}
template <typename TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator*(const double mnoznik) const //mnozenie wektora przez liczbe
{
  Wektor W;

  for (int i = 0; i < ROZMIAR; ++i)
    W.tablica[i] = this->tablica[i] * mnoznik;

  return W;
}
template <typename TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator/(const double dzielnik) const //dzielenie wektora przez liczbe
{
  Wektor W;
  if (dzielnik != 0)
  {
    for (int i = 0; i < ROZMIAR; ++i)
      W.tablica[i] = this->tablica[i] / dzielnik;
  }
  else
  {
    std::cout << "Błąd:dzielenie przez 0" << std::endl;
    exit(1);
  }
  return W;
}
template <typename TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator+(const Wektor &W2) const //dodawanie dwoch wektorow
{
  Wektor W;

  for (int i = 0; i < ROZMIAR; ++i)
    W.tablica[i] = this->tablica[i] + W2.tablica[i];

  return W;
}
template <typename TYP, int ROZMIAR>
Wektor<TYP, ROZMIAR> Wektor<TYP, ROZMIAR>::operator-(const Wektor &W2) const //odejmowanie dwoch wektorow
{
  Wektor W;
  for (int i = 0; i < ROZMIAR; ++i)
    W.tablica[i] = this->tablica[i] - W2.tablica[i];

  return W;
}

/*
double dlugosc_wektora(const Wektor W)
{
    double dl = 0;
    for (int a = 0; a < ROZMIAR; ++a)
        dl += W[a] * W[a];
    dl = sqrt(dl);
    return dl;
}*/

#endif
