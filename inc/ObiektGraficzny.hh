#ifndef OBIEKTGRAFICZNY_HH
#define OBIEKTGRAFICZNY_HH

/*!
 * \file
 * \brief Definicja klasy Obiekt graficzny
 *
 * Plik zawiera definicję klasy ObiektGraficzny.
 */

#include <iostream>
#include "Wektor2D.hh"
#include "Zbior_Wierzcholkow.hh"
class Robot;
class ObiektGraficzny:public ZbiorWierzcholkow
{

public:
     double PolozenieX(){return _PolozenieObiektu[0];}
     double PolozenieY(){return _PolozenieObiektu[1];}
    bool ZapiszDoPliku(const char* sNazwaPliku) const;
         virtual bool zapisz() const =0;
              virtual bool sprawdz_kolizje(Robot &){return false;}
protected:
    double KatOrientacji_rad;
    std::string nazwa_pliku;
    Wektor2D   _PolozenieObiektu;
    ObiektGraficzny(){ KatOrientacji_rad=0; }

    bool ZapiszDoStrumienia(std::ostream& StrmWy) const;

    void ZmienPolozenie(double x, double y);

};
#endif
