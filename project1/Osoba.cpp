include "Osoba.h"
Osoba::Osoba()
{
}
Osoba::Osoba(string _imie, string _nazwisko, string _miejscowosc)
:imie(_imie),nazwisko(_nazwisko),miejscowosc(_miejscowosc)
{
    cout<<"utworzono obiekt Osoba"<<" "<<nazwisko<<endl;
}
Osoba::~Osoba()
{
}
Osoba::Osoba(const Osoba& other)
{
    imie=other.imie+" kopia";
    nazwisko= other.nazwisko;
    miejscowosc=other.miejscowosc;
    cout<<endl<<"utworzono kopie "<<endl;
}
void Osoba::Wypisz() const
{
    cout<<endl<<"Imie: "<<imie;
    cout<<endl<<"nazwisko: "<<nazwisko;
    cout<<endl<<"miejscowosc: "<<miejscowosc;
    cout<<endl;

}