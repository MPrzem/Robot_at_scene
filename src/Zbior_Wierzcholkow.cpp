#include "Zbior_Wierzcholkow.hh"
int ZbiorWierzcholkow::liczba_w=0;

void ZbiorWierzcholkow::DodajWierzcholek(double x,double y)
{
    Wektor2D W;
    W[0]=x;
    W[1]=y;
    DodajWierzcholek(W);
}
void ZbiorWierzcholkow::DodajWierzcholek(const Wektor2D& W)
{
    wierzcholki.push_back(W);
    liczba_w++;
}

void ZbiorWierzcholkow::UsunWszystkie()
{
    wierzcholki.clear();
}
void ZbiorWierzcholkow::ZmienOstatni(Wektor2D &W)
{
    Wektor2D W1;
    wierzcholki.back()=W1;
}

void ZbiorWierzcholkow::wysw_liczbe_wierz(){
    std::cout<<"Liczba stworzonych wektorow 2D:   " ;
std::cout<<liczba_w<<std::endl;
}

