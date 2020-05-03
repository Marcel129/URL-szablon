#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>
using namespace std;

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
class LZespolona
{
  double re; /*! Pole repezentuje czesc rzeczywista. */
  double im; /*! Pole repezentuje czesc urojona. */

public:
  LZespolona(){re=0;im=0;};
  LZespolona(double r, double i)
  {
    re = r;
    im = i;
  };
  explicit LZespolona(double r)
  {
    re = r;
    im = 0;
  };
  void set_re(double r){this->re=r;};
  void set_im(double i){this->im=i;};
  const double get_re()const{return this->re;}
  const double get_im()const{return this->im;}

  LZespolona operator+(const LZespolona &Skl2) const;
  LZespolona operator-(const LZespolona &Skl2) const;
  LZespolona operator*(const LZespolona &Skl2) const;
  LZespolona operator/(const LZespolona &Skl2) const;
  LZespolona operator*(const double &Skl2) const;
  LZespolona operator/(const double &Skl2) const;
  void operator=(const double &liczba){this->re=liczba;this->im=0;};

  LZespolona sprzezenie()const; //funkcja obliczjaca sprzezenie liczby zes
  double modul()const;       //funkcja obliczjaca modul liczby zes
  bool operator!=(const double)const; //operator porównania liczby zespolonej z liczbą rzeczywistą

};

istream &operator>>(istream &strWej, LZespolona &wyr);       //przeciążenie operatora >> dla liczby zespolonej
ostream &operator<<(ostream &strWyj, const LZespolona &wyr); //przeciążenie operatora << dla liczby zespolonej


#endif
