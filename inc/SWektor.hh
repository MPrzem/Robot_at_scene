#ifndef SWEKTOR_HH
#define SWEKTOR_HH


#include <iostream>



//Szablon wektora. Do stworzenia instancji można użyć dowolnego typu dla którego zdefiniowano podstawowe działania matematyczne.
template <typename STyp, int SWymiar>
class SWektor
{
    STyp  _Wsp[SWymiar];
public:
    SWektor()
    {

        for (STyp &Wsp: _Wsp)
            Wsp = 0;
    }

   //Dostęp do składowych wektora w trybie do odczytu
    STyp  operator [] (unsigned int Ind) const
    {
        return _Wsp[Ind];
    }
    //Dostęp do składowych wektora rownież w trybie modyfikacji.
    STyp &operator [] (unsigned int Ind)
    {
        return _Wsp[Ind];
    }
    SWektor<STyp,SWymiar> operator - (const SWektor<STyp,SWymiar> &Odjemnik) const;
    SWektor<STyp,SWymiar> operator + (const SWektor<STyp,SWymiar> &Skl2) const;
    SWektor<STyp,SWymiar> operator * (double Mnoznik) const;
    STyp operator * (const SWektor<STyp,SWymiar> &W)const;
};




template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator - (const SWektor<STyp,SWymiar> &Odjemnik) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
        Wynik[Ind] = (*this)[Ind] - Odjemnik[Ind];
    return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator + (const SWektor<STyp,SWymiar> &Skl2) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
        Wynik[Ind] = (*this)[Ind] + Skl2[Ind];
    return Wynik;
}


template <typename STyp, int SWymiar>
SWektor<STyp,SWymiar> SWektor<STyp,SWymiar>::operator * (double Mnoznik) const
{
    SWektor<STyp,SWymiar>  Wynik;

    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
        Wynik[Ind] = (*this)[Ind]*Mnoznik;
    return Wynik;
}
template <typename STyp, int SWymiar>
STyp SWektor<STyp,SWymiar>::operator * (const SWektor<STyp,SWymiar> &W)const
{
    STyp iloczyn_skal;
    iloczyn_skal=0.0;
    for(unsigned int i=0; i<SWymiar; ++i)
    {
        iloczyn_skal=iloczyn_skal+_Wsp[i]*W._Wsp[i];
    }

    return iloczyn_skal;
}

//przeciążenie operra strumienia wyjscia, zdefiniowane poza klasą ponieważ lewym argumentem musi być referencja do strumienia

template <typename STyp, int SWymiar>
std::ostream& operator << (std::ostream &StrmWyj, const SWektor<STyp,SWymiar>& W)
{
    for (unsigned int Ind = 0; Ind < SWymiar; ++Ind)
    {
        StrmWyj << " " << W[Ind];
    }
    return StrmWyj;
}

#endif
