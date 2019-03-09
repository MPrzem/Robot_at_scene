#ifndef Zbior_Wierzcholkow_HH
#define Zbior_Wierzcholkow_HH
#include <iostream>
#include "Wektor2D.hh"
#include <vector>

class Robot;
class Przeszkoda;
class ZbiorWierzcholkow
{
friend class Robot;
    friend class Przeszkoda;

protected:
    std::vector<Wektor2D> wierzcholki;
public:
     static int liczba_w;
    void DodajWierzcholek(double x,double y);
    void DodajWierzcholek(const Wektor2D& W);
    void UsunWszystkie();
    void ZmienOstatni(Wektor2D& W);
    static void wysw_liczbe_wierz();
};
#endif

