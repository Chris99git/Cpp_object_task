#include <iostream>
using namespace std;
class Pracownik
{
private:
    string imie;
    string nazwisko;
    string stanowisko;
public:
    Pracownik(string _imie,string _nazwisko, string _stanowisko)
        :imie(_imie),nazwisko(_nazwisko),stanowisko(_stanowisko)
    {
        cout<<endl<<"this is me Pracownik";
    }
    void Wyswietl() const
    {
        cout << endl << imie << " " << nazwisko << " " << stanowisko;
    }
};
class PracownikEtatowy :public Pracownik
{
private:
    double placaBrutto;
public:
    PracownikEtatowy(string _imie, string _nazwisko, string _stanowisko, double _placaBrutto)
        :Pracownik(_imie, _nazwisko, _stanowisko), placaBrutto(_placaBrutto)
    {
        cout<<endl<<"this is me etatowy";
    }
    void Wyswietl() const
    {
        Pracownik::Wyswietl();
        cout << endl << placaBrutto;
    }
};
class Kierownik:public PracownikEtatowy
{
private:
    string kierowanyDzial;
public:
    Kierownik(string _imie, string _nazwisko, string _stanowisko, double _placaBrutto, string _kierowanyDzial)
        :PracownikEtatowy(_imie, _nazwisko, _stanowisko, _placaBrutto), kierowanyDzial(_kierowanyDzial)
    {
        cout<<endl<<"this is me kierownika";
    }
    void Wyswietl() const
    {
        PracownikEtatowy::Wyswietl();
        cout << endl << kierowanyDzial;
    }
};
int main()
{
    Kierownik k1("Jan", "Nowak", "Kierownik", 2000, "marketing");
    k1.Wyswietl();
}
