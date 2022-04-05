#include <iostream>
using namespace std;
class Czas
{
private:
    int godzina;
    int minuta;
public:
    Czas()
    {
    }
    Czas(int godzina,int minuta)
        :godzina(godzina),minuta(minuta)
    {
    }
    void Wczytaj();
    void Prezentuj()
    {
        cout<<endl<<godzina<<":"<<minuta;
    }
};
class Warsztat
{
private:
    Czas czasRozpoczecia;
    Czas czasZakonczenia;
    string nazwaWarsztatu;
    string nazwiskoProwadzacego;
    string sala;
public:
    Warsztat()
    {
    }
    Warsztat(int godzinaRozpoczecia,int minutaRozpoczecia,int godzinaZakonczenia,
             int minutaZakonczenia,string nazwaWarsztatu,string nazwisko, string sala)
        :czasRozpoczecia(godzinaRozpoczecia,minutaRozpoczecia),
         czasZakonczenia(godzinaZakonczenia,minutaZakonczenia),
         nazwaWarsztatu(nazwaWarsztatu),nazwiskoProwadzacego(nazwisko),
         sala(sala)
    {
    }
    Warsztat(Czas rozpoczecie, Czas zakonczenie,string nazwaWarsztatu,string nazwisko,string sala)
    :czasRozpoczecia(rozpoczecie),czasZakonczenia(zakonczenie),nazwaWarsztatu(nazwaWarsztatu),nazwiskoProwadzacego(nazwisko),sala(sala)
    {

    }
    void Wyswietl()
    {
        cout<<endl<<endl<<"info o warsztacie: ";
        cout<<endl<<"Start: ";
        czasRozpoczecia.Prezentuj();
        cout<<endl<<"Koniec: ";
        czasZakonczenia.Prezentuj();
        cout<<endl<<"Nazwaa: "<<nazwaWarsztatu;
        cout<<endl<<"Nazwisko: "<<nazwiskoProwadzacego;
        cout<<endl<<"Sala: "<<sala;
    }
};
void Czas::Wczytaj()
{
    cout<<endl<<"podaj godzine: ";
    cin>>godzina;
    cout<<endl<<"podaj minute: ";
    cin>>minuta;
}
int main()
{
    Czas c1;
    Czas c2(5,25);
    c1.Wczytaj();
    c1.Prezentuj();
    c2.Prezentuj();
    Warsztat w1(6,30,15,30,"supi","kowalski","C115");
    w1.Wyswietl();

    Warsztat w2(c1,c2,"majca ","nowak","c215");
    w2.Wyswietl();
    Warsztat w3(Czas(10,0),Czas(13,0),"programowanie ","tomek","C010");
    w3.Wyswietl();
}
