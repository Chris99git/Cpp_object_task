#include <iostream>
using namespace std;
class Zawodnik
{
private:
    string imie;
    string nazwisko;
public:
    Zawodnik()
    {
        cout<<"utworzono zawodnika"<<endl;
    }
    Zawodnik(string _imie,string _nazwisko);
    void Wczytaj()
    {
        cout<<endl<<"podaj imi i nazwisko: ";
        cin>>imie>>nazwisko;
    }
    void Wypisz()const
    {
        cout<<endl<<"zawodnik: "<<imie<<" "<<nazwisko;
    }
    ~Zawodnik()
    {
        cout<<endl<<"usuwa zawodnika "<<nazwisko;
    }

};
Zawodnik::Zawodnik(string _imie,string _nazwisko)
    :imie(_imie),nazwisko(_nazwisko)
{
    cout<<"zawodnik: "<<nazwisko;
}
class Zawody
{
private:
    string nazwa;
    int liczbaZawodnikow;
    int maxZawodnikow;
    Zawodnik* tablicaZawodnikow;
public:
    Zawody(string _nazwa, int _maxLiczbaZawodnikow)
    {
        nazwa=_nazwa;
        maxZawodnikow=_maxLiczbaZawodnikow;
        tablicaZawodnikow=new Zawodnik[_maxLiczbaZawodnikow];
        liczbaZawodnikow=0;
    }
    ~Zawody()
    {
        delete[] tablicaZawodnikow;
        cout<<endl<<"zawody zakonczone ";
    }
    void DodajZawodnika()
    {
        tablicaZawodnikow[liczbaZawodnikow++].Wczytaj();
    }
    void WypiszZawodnikow() const
    {
        for (int i=0; i<liczbaZawodnikow; i++)
        {
            tablicaZawodnikow[i].Wypisz();
        }
    }
    void DodajZawodnika(Zawodnik z)
    {
       tablicaZawodnikow[liczbaZawodnikow++]=z;
    }

};
int main()
{
    Zawodnik z1;
    Zawodnik z2 ("olo","kowal");
    z1.Wczytaj();
    z1.Wypisz();
    Zawody zawody("plywanie",15);
    zawody.DodajZawodnika();
    zawody.DodajZawodnika();
    zawody.DodajZawodnika(z2);

    zawody.WypiszZawodnikow();
}
