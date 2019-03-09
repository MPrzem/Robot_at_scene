#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH
#include"ObiektGraficzny.hh"
#include"SMacierz.hh"
#include"Robot.hh"
class Robot;
class Przeszkoda:public ObiektGraficzny
{

protected:
    ZbiorWierzcholkow ZbiorAproksymacji;
public:
//tylko jawnie wywolanie aby nie przypisac int do przeszkody
    explicit Przeszkoda(int szerokosc=40,int wysokosc=60,int X=50,int Y=100, int R=30);

    void Dodaj_Z_Aproksymacji(int szerokosc,int wysokosc,int R,int X,int Y);

    ~Przeszkoda()
    {
        UsunWszystkie();
        ZbiorAproksymacji.UsunWszystkie();
    }

    bool zapisz()const ;
    bool sprawdz_kolizje(Robot &) override;
    bool kolizja_OX(int X_robota);
    bool kolizja_OY(int Y_robota);
};
#endif
