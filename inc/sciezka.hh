#ifndef SCIEZKA_HH
#define SCIEZKA_HH
#include"ObiektGraficzny.hh"

class Sciezka:public ObiektGraficzny{
public:
     //konstruktor scieżki nadaje jej punkt poczatkowy taki jak współrzędne globalne robota.
     Sciezka(int X,int Y){
     DodajWierzcholek(X,Y);
     }

~Sciezka(){UsunWszystkie();}
bool zapisz()const{return true;}
};
#endif
