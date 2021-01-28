#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include "lacze_do_gnuplota.hh"
#include "ObiektGraficzny.hh"
#include "Obiekt_Geometryczny.hh"
#include "Zbior_Wierzcholkow.hh"
#include "Robot.hh"
#include "SMacierz.hh"
#include "Scena.hh"
#include <unistd.h>
#define ROZMIAR 2

using namespace std;
void wyswietl_menu();
void sterowanie(Scena &,PzG::LaczeDoGNUPlota &);
void lacze_inicjalizacja(PzG::LaczeDoGNUPlota &);
int main()
{

    PzG::LaczeDoGNUPlota  Lacze;
    lacze_inicjalizacja(Lacze);
    Scena &Sc1=Scena::pobierzInstancje();
    ZbiorWierzcholkow::wysw_liczbe_wierz();
    Sc1.ZapiszDoPlikow();
    wyswietl_menu();
    sterowanie(Sc1,Lacze);

}

void lacze_inicjalizacja(PzG::LaczeDoGNUPlota & Lacze1)
{
    Lacze1.DodajNazwePliku("../figury/robot",PzG::RR_Ciagly,2);
    Lacze1.DodajNazwePliku("../figury/robots",PzG::RR_Ciagly,2);
    Lacze1.DodajNazwePliku("../figury/przeszkody",PzG::RR_Ciagly,2);
}

void wyswietl_menu()
{
    cout<<"o - obrot robota"<<endl;
    cout<<"j - jazda na wprost"<<endl;
    cout<<"w - wyswietl ponownie menu"<<endl;
    cout<<"R - Dodaj robota"<<endl;
    cout<<"P - Dodaj przeszkode"<<endl;
    cout<<"k - zakoncz dzialanie programu"<<endl;
}

unsigned int wybor_r()
{
    unsigned int wybor_robota;
    cout<<"Wybierz robota wpisując odpowiadajacy mu liczbe calkowitą(0,1,2...)";
    cin>>wybor_robota;
    if(wybor_robota>=Scena::Get_ilosc_robotow()-1)
    {
        cout<<"nie ma robota o tym numerze";
        return 0;
    }
    return wybor_robota;
}

void sterowanie(Scena & Sc1,PzG::LaczeDoGNUPlota & Lacze1)
{
    Lacze1.Rysuj();//Rysowanie sceny w warunkach pocztkowych
    char menu;
    double kat_zadany,dlugosc_ruchu;
    do
    {
        cin>>menu;
        switch( menu )
        {
        case 'o':
        {
            cout<<"Wpisz wartosc kata w stopniach";
            cin>>kat_zadany;
            Sc1.ObrocRobota(wybor_r(),kat_zadany);
            Lacze1.Rysuj();
        }
        break;
        case 'j':
        {
            cout<<"Podaj na jaka odleglosc ma pojechac robot";
            cin>>dlugosc_ruchu;
            Sc1.JedzRobotem(wybor_r(),dlugosc_ruchu,Lacze1);
           // Lacze1.Rysuj();
        }
        break;
        case 'm':
            wyswietl_menu();
            break;
        case 'r':
            Sc1.DodajRobota();
            Lacze1.Rysuj();
            break;
        case 'p':
            Sc1.DodajPrzeszkode();
            Lacze1.Rysuj();
        }
        cout<<"Liczba stworzonych wektorow 2D:   " ;
        ZbiorWierzcholkow::wysw_liczbe_wierz();
    }
    while (menu != 'k');
}
