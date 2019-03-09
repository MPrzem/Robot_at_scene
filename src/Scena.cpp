#include "Scena.hh"
#include <fstream>

unsigned int Scena::ilosc_robotow=0;
Scena::Scena()
{
    DodajRobota(-100,0);
    DodajRobota(0,100);
    DodajRobota(100,0);
    DodajPrzeszkode(40,40,100,100);
    DodajPrzeszkode(40,40,-100,-100);
    DodajPrzeszkode(40,40,300,200);

}

bool Scena::ZapiszDoPlikow()
{
//Otwieranie i zamykanie plików służy ich wyczyszczeniu
    std::ofstream fileOut;
    fileOut.open("figury/robot");
    if(!fileOut.good())
    {
        std::cerr<<"Otwarcie pliku nie powiodło sie";
        return false;
    }
    fileOut.close();
    fileOut.open("figury/robots");
    if(!fileOut.good())
    {
        std::cerr<<"Otwarcie pliku nie powiodło sie";
        return false;
    }
    fileOut.close();
    fileOut.open("figury/przeszkody");
    if(!fileOut.good())
    {
        std::cerr<<"Otwarcie pliku nie powiodło sie";
        return false;
    }
    fileOut.close();

    std::list<std::shared_ptr<ObiektGraficzny>>::iterator it;
    for( it=L_pelna.begin(); it!=L_pelna.end(); ++it )
    {
        (*it)->zapisz();
    }
    return true;
}

bool Scena::SprawdzKolizje(std::shared_ptr<Robot> Wybrany)
{
    std::list<std::shared_ptr<ObiektGraficzny>>::iterator ito;

    for( ito=L_pelna.begin(); ito!=L_pelna.end(); ++ito )
    {
        if((*ito)->sprawdz_kolizje(*Wybrany))
        {
            return true;
        }
    }
    return false;
}

void Scena::JedzRobotem(unsigned int nr_robota,int dlugosc_ruchu,PzG::LaczeDoGNUPlota & lacze)
{
    std::shared_ptr<Robot> robot_wybrany=V_robotow[nr_robota];

    for(int i=dlugosc_ruchu; i>0; --i)
    {
        robot_wybrany->JazdaNaprzod(1);
        if(SprawdzKolizje((robot_wybrany)))
        {
            std::cout<<std::endl<<"KOLIZJA"<<std::endl;
            //jesli byla kolizja to cofnij robota i wyjdz z pętli
            robot_wybrany->JazdaNaprzod(-1);
            break;
        }
                usleep(2000);
                robot_wybrany->s.DodajWierzcholek(robot_wybrany->_PolozenieObiektu);
                ZapiszDoPlikow();
                lacze.Rysuj();

    }
}

void Scena::ObrocRobota(unsigned int nr_robota,int kat_zadany)
{
    std::shared_ptr<Robot> robot_wybrany=V_robotow[nr_robota];
    robot_wybrany->Obrot(kat_zadany);
    ZapiszDoPlikow();
}

void Scena::DodajRobota(int X,int Y)
{
    std::shared_ptr<Robot> Rbb1= std::make_shared<Robot>(X,Y);
    V_robotow.push_back(Rbb1);
    L_pelna.push_back(Rbb1);
    ++ilosc_robotow;
}

void Scena::DodajRobota()
{
    int X,Y;
    std::cout<<"Podaj wsp X:";
    std::cin>>X;
    std::cout<<"Podaj wsp Y:";
    std::cin>>Y;
    std::shared_ptr<Robot> Rbb1= std::make_shared<Robot>(X,Y);
    V_robotow.push_back(Rbb1);
    L_pelna.push_back(Rbb1);
    ++ilosc_robotow;
    ZapiszDoPlikow();//Funkcja przeciazona aby wywolanie w menu powodowalo zapisanie do pliku nowego elementu
}


void Scena::DodajPrzeszkode(int szerokosc,int wysokosc,int X,int Y)
{
    std::shared_ptr<Przeszkoda> Prz1=std::make_shared<Przeszkoda>(szerokosc,wysokosc,X,Y);
    L_pelna.push_back(Prz1);
}

void Scena::DodajPrzeszkode()
{
    int X,Y,szerokosc,wysokosc;
    std::cout<<"Podaj wsp szerokosc:";
    std::cin>>szerokosc;
    std::cout<<"Podaj wsp wysokosc:";
    std::cin>>wysokosc;
    std::cout<<"Podaj wsp X:";
    std::cin>>X;
    std::cout<<"Podaj wsp Y:";
    std::cin>>Y;
    std::shared_ptr<Przeszkoda> Prz1=std::make_shared<Przeszkoda>(szerokosc,wysokosc,X,Y);
    L_pelna.push_back(Prz1);
    ZapiszDoPlikow();
}

