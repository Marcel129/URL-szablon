#include "LZespolona.hh"

istream &operator>>(istream &strWej, LZespolona &wyr)
{
  {
    char kosz;
    double a;
    strWej >> kosz;
    if (kosz == '(')
    {
      strWej >> a;
      wyr.set_re(a);
      if (strWej.fail() == false)
      {
        strWej >> a;
        wyr.set_im(a);
        if (strWej.fail() == false)
        {
          strWej >> kosz;
          if (kosz == 'i')
          {
            strWej >> kosz;
            if (kosz == ')')
            {
              return strWej;
            }
          }
        }
        else //przypadek, kiedy wczyta jedna liczbe, a nastepny jest znak
        {
          strWej.clear();
          strWej >> kosz;
          if (strWej.fail() == false)
          {
            if (kosz == 'i') //kiedy po wczytaniu liczby wystepuje i, czyli jest sama czesc urojona
            {
              wyr.set_im(wyr.get_re());
              wyr.set_re(0);
              strWej >> kosz;
              if (kosz == ')')
              {
                return strWej;
              }
            }
            else if (kosz == ')') //kiedy po wczytaniu liczby nie wystepuje i, czyli jest sama czesc rzeczywista
            {
              wyr.set_im(0);
              return strWej;
            }
          }
        }
      }
      else //przypadek, kiedy liczba jest samo i
      {
        strWej.clear();
        strWej >> kosz;
        if (kosz == 'i')
        {
          wyr.set_im(1);
          wyr.set_re(0);
          strWej >> kosz;
          if (kosz == ')')
          {
            return strWej;
          }
        }
      }
    }
  }
  strWej.setstate(std::ios::failbit);

  return strWej;
}

ostream &operator<<(ostream &strWyj, const LZespolona &wyr)
{
  cout << '(' << wyr.get_re() << showpos << wyr.get_im() << noshowpos << "i)";
  return strWyj;
}

LZespolona LZespolona::operator+(const LZespolona &Skl2) const
{
  LZespolona Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator-(const LZespolona &Skl2) const
{
  LZespolona Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}

LZespolona LZespolona::operator*(const LZespolona &Skl2) const
{
  LZespolona Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + this->im * Skl2.re;
  return Wynik;
}

LZespolona LZespolona::operator/(const LZespolona &Skl2) const //dzielenie liczby zespolonej przez liczbe zepolona
{
  LZespolona Wynik, Iloczyn;
  double modulKwadrat; //zmienna pomocnicza do obliczenia modulu
  if (Skl2 != 0)    //sprawdz, czy druga liczba nie jest zerem
    //pierwszy w kolejności jest warunek na rownosc z zerem, poniewaz w przeciwnym wypadku kompilator zwraca ostrzezenie
    {

      Iloczyn = *this * Skl2.sprzezenie();  //jesli nie, oblicz jej sprzezenie i pomnoz przez nie pierwsza liczbe
      modulKwadrat = pow(Skl2.modul(), 2);  //oblicz kwadrat modulu drugiej liczby
      Wynik.re = Iloczyn.re / modulKwadrat; //podstaw obliczone wartosci do wyniku
      Wynik.im = Iloczyn.im / modulKwadrat;

      return Wynik;
    }
  cerr << "Dzielenie przez 0" << endl; //jesli jest zerem, wyswietl komunikat
  exit(1);
}

LZespolona LZespolona::operator/(const double &Skl2) const //dzielenie liczby zespolonej przez liczb rzeczywista
{
  LZespolona Wynik;

  if (Skl2 == 0) //sprawdz, czy druga liczba nie jest zerem
  //pierwszy w kolejności jest warunek na rownosc z zerem, poniewaz w przeciwnym wypadku kompilator zwraca ostrzezenie
  {
    cerr << "Dzielenie przez 0" << endl; //jesli jest zerem, wyswietl komunikat
    exit(1);
  }
  Wynik.re = this->re / Skl2; //podstaw obliczone wartosci do wyniku
  Wynik.im = this->im / Skl2;

  return Wynik;
}

LZespolona LZespolona::operator*(const double &Skl2) const //mnożenie liczby zespolonej przez liczb rzeczywista
{
  LZespolona Wynik;

  Wynik.re = this->re * Skl2;
  Wynik.im = this->im * Skl2;

  return Wynik;
}

bool LZespolona::operator!=(const double odniesienie) const
{
  double modulLiczby = this->modul();
  if (modulLiczby != odniesienie)
    return true;
  return false;
}

LZespolona LZespolona::sprzezenie() const
{
  LZespolona sprzezenie;
  sprzezenie.re = this->re;
  sprzezenie.im = -this->im;
  return sprzezenie;
}

double LZespolona::modul() const
{
  double modul = sqrt(pow(this->re, 2) + pow(this->im, 2));
  return modul;
}