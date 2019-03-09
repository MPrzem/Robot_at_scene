
#ifndef ROBOT_HH
#define ROBOT_HH
#include"ObiektGraficzny.hh"
#include "Zbior_Wierzcholkow.hh"
#include <math.h>
#include <cmath>
#include"SMacierz.hh"
#include"sciezka.hh"
#include <string>
#include<memory>


 class Scena;
class Robot:public ObiektGraficzny
{
friend class Scena;
    ZbiorWierzcholkow Zb_org;
    Macierz<double,2> M;
    Sciezka s;
public:
    explicit Robot(int X=0, int Y=0);

    ~Robot()
    {
        UsunWszystkie();
    }
    void Obrot(double kat_deg);
    void JazdaNaprzod(int ile);
    bool ZapiszDoPlikuZeSciezka(const char* sNazwaPliku) const;
    bool zapisz() const;
    bool sprawdz_kolizje(Robot &) override;
};
#endif
