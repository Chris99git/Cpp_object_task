#include <iostream>
using namespace std;
class Osoba
{
private:
    string imie;
    string nazwisko;
public:
    Osoba(string _imie, string _nazwisko)
        :imie(_imie),nazwisko(_nazwisko)
    {

    }
    void Wypisz() const
    {
        cout<<endl<<imie<<endl<<nazwisko<<endl;
    }

};
class Ksiazka
{
    string tytul;
    double cena;
    Osoba autor;
public:
    Ksiazka(string _tytul,double _cena, string _imie, string _nazwisko)
    :tytul(_tytul),cena(_cena),autor(_imie,_nazwisko)
    {

    }
    void Wypisz() const
    {
        autor.Wypisz();
        cout<<tytul<<endl<<cena<<endl;
    }
};
int main()
{
    Ksiazka k1("dziady",30,"Adam","mickiewicz");
    k1.Wypisz();
    return 0;
}
