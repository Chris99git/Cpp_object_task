#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;
class Pracownik
{
private:
    string imie;
    string nazwisko;
public:
    Pracownik()
    {}
    void Wpisz()
    {
        cout<<endl<<"podaj imi i nazwisko: ";
        cin>>imie>>nazwisko;
    }
    void Wypisz()const
    {
        cout<<endl<<"pracownik: "<<imie<<" "<<nazwisko;
    }
    ~Pracownik()
    {
        cout<<endl<<"usuwa pracownika "<<nazwisko;
    }
};
class Firma
{
private:
    string nazwa;
    int liczbaPracownikow;
    int maxPracownikow;
    Pracownik* tablicaPracownikow;
public:
    Firma(string _nazwa, int _maxLPracownikow)
    {
        nazwa=_nazwa;
        maxPracownikow=_maxLPracownikow;
        tablicaPracownikow=new Pracownik[_maxLPracownikow];
        liczbaPracownikow=0;
}
~Firma()
{
    delete[] tablicaPracownikow;
    cout<<endl<<"zawody zakonczone ";
}

void DodajPracownika()
    {
        tablicaPracownikow[liczbaPracownikow++].Wpisz();
    }
    void WypiszPracownikow() const
    {
        for (int i=0; i<liczbaPracownikow; i++)
        {
            tablicaPracownikow[i].Wypisz();
        }
    }
};
int main()
{
    Pracownik p1;
    Pracownik p2;
    p1.Wpisz();
    p1.Wypisz();
    p2.Wpisz();
    p2.Wypisz();
    Firma firma("xkom",20);
    firma.DodajPracownika();
    firma.DodajPracownika();
    firma.DodajPracownika();
    firma.WypiszPracownikow();
}