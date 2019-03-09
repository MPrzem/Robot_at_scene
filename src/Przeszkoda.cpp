#include"Przeszkoda.hh"
class Robot;

Przeszkoda::Przeszkoda(int szerokosc,int wysokosc,int X,int Y, int R)
    {
        Dodaj_Z_Aproksymacji(szerokosc,wysokosc,R,X,Y);

        DodajWierzcholek(szerokosc/2,wysokosc/2);
        DodajWierzcholek(-szerokosc/2,wysokosc/2);
        DodajWierzcholek(-szerokosc/2,-wysokosc/2);
        DodajWierzcholek(szerokosc/2,-wysokosc/2);
        DodajWierzcholek(szerokosc/2,wysokosc/2);

        _PolozenieObiektu[0]=X;
        _PolozenieObiektu[1]=Y;

    }

bool Przeszkoda::zapisz()const{
return ZapiszDoPliku("figury/przeszkody");
}


void Przeszkoda::Dodaj_Z_Aproksymacji(int szerokosc,int wysokosc,int R,int X,int Y)
{
        ZbiorAproksymacji.DodajWierzcholek(szerokosc/2+R+X,wysokosc/2+R+Y);
        ZbiorAproksymacji.DodajWierzcholek(-szerokosc/2-R+X,wysokosc/2+R+Y);
        ZbiorAproksymacji.DodajWierzcholek(-szerokosc/2-R+X,-wysokosc/2-R+Y);
        ZbiorAproksymacji.DodajWierzcholek(szerokosc/2+R+X,-wysokosc/2-R+Y);
}




bool Przeszkoda::sprawdz_kolizje(Robot & Wybrany) {

if(kolizja_OX(Wybrany.PolozenieX())&&kolizja_OY(Wybrany.PolozenieY()))
return true;
else return false;
}
bool Przeszkoda::kolizja_OX(int X_robota){
if(ZbiorAproksymacji.wierzcholki[0][0]>=X_robota&&X_robota>=ZbiorAproksymacji.wierzcholki[1][0])
return true;
else return false;


}
bool Przeszkoda::kolizja_OY(int Y_robota){
if(ZbiorAproksymacji.wierzcholki[0][1]>=Y_robota&&Y_robota>=ZbiorAproksymacji.wierzcholki[3][1])
return true;
else return false;

return false;
}
