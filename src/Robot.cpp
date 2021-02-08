#include "Robot.hh"

Robot::Robot(int X, int Y):s(X,Y)
{
    _PolozenieObiektu[0]=X;
    _PolozenieObiektu[1]=Y;
    DodajWierzcholek(0,0);
    DodajWierzcholek(30,0);
    DodajWierzcholek(0,-30);
    DodajWierzcholek(-30,-30);
    DodajWierzcholek(-30,30);
    DodajWierzcholek(0,30);
    DodajWierzcholek(30,0);
    Zb_org.wierzcholki=wierzcholki;
}


void Robot::Obrot(double kat_deg)
{
    KatOrientacji_rad=KatOrientacji_rad+(kat_deg*M_PI/180);
    M[0][0]=cos(KatOrientacji_rad);
    M[0][1]=-sin(KatOrientacji_rad);
    M[1][0]=sin(KatOrientacji_rad);
    M[1][1]=cos(KatOrientacji_rad);

    for (unsigned i=0; i<wierzcholki.size() ; i++)
    {
        wierzcholki[i]=M*Zb_org.wierzcholki[i];

    }
}
void Robot::JazdaNaprzod(int ile)
{
    _PolozenieObiektu[0]+=ile*cos(KatOrientacji_rad);
    _PolozenieObiektu[1]+=ile*sin(KatOrientacji_rad);
}

bool Robot::zapisz() const
{
    return (s.ZapiszDoPliku("../figury/robots"))&&(ZapiszDoPliku("../figury/robot"));

}

bool Robot::sprawdz_kolizje(Robot & Wybrany)
{
    Wektor2D wektor_odleglosci=Wybrany._PolozenieObiektu-this->_PolozenieObiektu;
    double odleglosc=sqrt(wektor_odleglosci[0]*wektor_odleglosci[0]+wektor_odleglosci[1]*wektor_odleglosci[1]);
    if((odleglosc<(60))&&odleglosc!=0)
        return true;
    return false;

}

