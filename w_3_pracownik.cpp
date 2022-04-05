#include <iostream>
using namespace std;
class Pracownik
{
private:
    string imie;
    string stanowisko;
protected:
    string nazwisko;
public:
    Pracownik(string _imie, string _nazwisko, string _stanowisko)
    :imie(_imie),nazwisko(_nazwisko),stanowisko(_stanowisko)
    {
    }
    void Wyswietl() const
    {
        cout<<endl<<imie<<" "<<nazwisko<<" "<<stanowisko;
    }
};
class PracownikGodzinowy : public Pracownik
{
private:
    double liczbaGodzin;
    double stawkaZaGodzine;
public:
    PracownikGodzinowy(string _imie, string _nazwisko, string _stanowisko, double _liczbaGodzin, double _stawkaZaGodzine)
    :Pracownik(_imie,_nazwisko,_stanowisko),liczbaGodzin(_liczbaGodzin),stawkaZaGodzine(_stawkaZaGodzine)
    {
    }
    void Wyswietl()const
    {
        Pracownik::Wyswietl();
        cout<<endl<<liczbaGodzine<<" "<<stawkaZaGodzine;
    }
};
class PracownikEtatowy: public Pracownik
{
private:
    double placaBrutto;
public:
    PracownikEtatowy(string _imie, string _nazwisko, string _stanowisko,double pracaBrutto(_pracaBtutto)
    {
    }
    void Wyswietl()const
    {
        Pracownik::Wyswietl();
        cout<<endl<<placaBrutto;
    }
    void WyswietlNazwiskoIPlace() const
    {
        cout<<endl<<nazwisko<<" "<<placaBrutto;
    }
};
int main()
{
    Pracownik p1("Maks","Kowal","Dyrektor");
    p1.Wyswietl();

    PracownikGodzinowy pg1("olaf","kot","kierownik",10,100);
    pg1.Wyswietl();

    PracownikEtatowy pe1("ola","lis",12,110);
    pe1.Wyswietl();
    pe1.WyswietlNazwiskoIPlace();

    return 0;
}
