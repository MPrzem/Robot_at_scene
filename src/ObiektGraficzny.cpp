#include <fstream>
#include "ObiektGraficzny.hh"


using namespace std;

void ObiektGraficzny::ZmienPolozenie(double x, double y)
{
    _PolozenieObiektu[0] = x;
    _PolozenieObiektu[1] = y;
}


bool ObiektGraficzny::ZapiszDoStrumienia(std::ostream& StrmWy) const
{
    Wektor2D  W_glob;

    for (unsigned int i=0; i<wierzcholki.size() ; i++)
    {
        W_glob = wierzcholki[i] + _PolozenieObiektu;
        StrmWy << W_glob << endl;
    }
    StrmWy<<endl<<"#"<<endl;
    return !StrmWy.fail();
}

bool ObiektGraficzny::ZapiszDoPliku(const char* sNazwaPliku) const
{
    ofstream   StrmWy(sNazwaPliku,ios_base::app);

    if (!StrmWy.is_open())
    {
        cerr << endl
             << "Blad: Otwarcie do zapisu pliku '" << sNazwaPliku
             << "' nie powiodlo sie." << endl
             << endl;
        return false;
    }
    return ZapiszDoStrumienia(StrmWy);
}
