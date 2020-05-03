#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "rozmiar.h"

template <typename TYP, int ROZMIAR>
class UkladRownanLiniowych
{
  Wektor<TYP, ROZMIAR> W;  //wektor wyrazów wolnych
  Macierz<TYP, ROZMIAR> M; //macierz współczynników
  Wektor<TYP, ROZMIAR> R;  //wektor rozwiązań układu

public:
  UkladRownanLiniowych(){};
  UkladRownanLiniowych(Macierz<TYP, ROZMIAR> MM, Wektor<TYP, ROZMIAR> WW)
  {
    M = MM;
    W = WW;
  };

  void wstawWektor(Wektor<TYP, ROZMIAR> wek) { W = wek; }
  const Wektor<TYP, ROZMIAR> &wezWektor() const { return W; }

  void wpiszRoz(Wektor<TYP, ROZMIAR> wek) { R = wek; }
  const Wektor<TYP, ROZMIAR> &wezRoz() const { return R; }

  void wstawMacierz(Macierz<TYP, ROZMIAR> mac) { M = mac; }
  const Macierz<TYP, ROZMIAR> &wezMacierz() const { return M; }

  void Oblicz();
  double Blad() const;
  Wektor<TYP, ROZMIAR> wektor_bledu() const;
};

template <typename TYP, int ROZMIAR>
std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

template <typename TYP, int ROZMIAR>
std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych<TYP, ROZMIAR> &UklRown);

#endif
