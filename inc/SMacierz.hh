#include <iostream>
#define ROZMIAR 2
#include "SWektor.hh"
#ifndef MACIERZ_HH
#define MACIERZ_HH
template <typename STyp, int SWymiar> class SWektor;
template <typename STyp, int SWymiar> class Macierz;
template<typename STyp, int SWymiar> std::istream& operator>>(std::istream&,Macierz<STyp,SWymiar>&);



template<typename STyp,int SWymiar>
class Macierz
{
    //Tablica wektorów, która reprezentuje macierz
    SWektor<STyp,SWymiar> tablica[SWymiar];
public:
    SWektor<STyp,SWymiar> operator* (SWektor<STyp,SWymiar>&);
//Operator indeksowania  do odczytu
    SWektor<STyp,SWymiar>  operator [] (unsigned int Ind) const
    {
        return tablica[Ind];
    }
//Operator indeskowaia do modyfikacji. W polaczeniu z operatorem indeksowania dla wektora mozemy dzialac na macierzy tak jak na tablicy dwuelementowej.
    SWektor<STyp,SWymiar> &operator [] (unsigned int Ind)
    {
        return tablica[Ind];
    }
    friend std::istream & operator >><STyp,SWymiar>( std::istream & strumien, Macierz<STyp,SWymiar> &W );
};

template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> Macierz<STyp,SWymiar>::operator*(SWektor<STyp,SWymiar> & W)
{
    SWektor<STyp,SWymiar> W1;
    for (int i=0; i<SWymiar; i++)
    {
        W1[i]=tablica[i]*W;
    }
    return W1;
}
template <typename STyp, int SWymiar>
std::istream& operator >> (std::istream &strumien,Macierz<STyp,SWymiar> &M)
{
    for (unsigned int i=0; i<ROZMIAR; ++i)
    {

        strumien>>M[i];
    }
    return strumien;
}
//Zapis do strumienia działa poprawnie o ile elementy kotre przechowuje macierz maja rownież zdefiniowany taki operator.
template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &strumien, const Macierz<STyp,SWymiar> &M)
{


    for (int i=0; i<ROZMIAR; ++i)

        strumien<<M[i]<<std::endl;

    return strumien;
}
#endif
