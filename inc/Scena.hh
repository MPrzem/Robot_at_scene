#ifndef SCENA
#define SCENA
#include "Robot.hh"
#include "Przeszkoda.hh"
#include "lacze_do_gnuplota.hh"
#include <cmath>
#include <memory>
#include <list>
#include <unistd.h>

class Scena
{

//Obiekty mieszczą sie w dwóch kontenerach, Lista pełna zawiera wszystkie elementy w celu zapisu i sprawdzania kolizji.
//Vector robotóœ zawiera same roboty w celu sterowania nimi
    static unsigned int ilosc_robotow;
    std::list<std::shared_ptr<ObiektGraficzny>> L_pelna;
    std::vector<std::shared_ptr<Robot>> V_robotow;
   Scena();
public:

//Implementacja Meyers Singleton
    static Scena& pobierzInstancje(){
        static Scena Instancja;
        return Instancja;
    }
    static unsigned int Get_ilosc_robotow(){return ilosc_robotow;}
    bool SprawdzKolizje(std::shared_ptr<Robot> Wybrany);
    bool ZapiszDoPlikow();
    void JedzRobotem(unsigned int nr_robota,int dlugosc_ruchu,PzG::LaczeDoGNUPlota & lacze);
    void ObrocRobota(unsigned int nr_robota,int kat_zadany);
    void DodajRobota(int X,int Y);
    void DodajRobota();
    void DodajPrzeszkode(int szerokosc,int wysokosc,int X,int Y);
    void DodajPrzeszkode();


};
#endif
