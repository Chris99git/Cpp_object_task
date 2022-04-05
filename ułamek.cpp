#include <iostream>
using namespace std;
int NWD(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int NWW(int a, int b)
{
    return a / NWD(a, b) * b;
}
class Ulamek
{
private:
    int licznik;
    int mianownik;
public:
    Ulamek(int licznik, int mianownik)
    {
        this->licznik = licznik;
        this->mianownik = mianownik;
    }
    Ulamek(int licznik)
    {
        this->licznik = licznik;
        mianownik = 1;
    }
    Ulamek()
    {
        licznik = 0;
        mianownik = 0;
    }
    void WczytajUlamek(int licznik, int mianownik)
    {
        this->licznik = licznik;
        this->mianownik = mianownik;
    }
    void WypiszUlamek()
    {
        cout << "Licznik: " << licznik << endl;
        cout << "Mianownik: " << mianownik << endl;
    }
    void Razy(Ulamek& x)
    {
        int LicznikPoRazy, MianownikPoRazy;
        LicznikPoRazy = licznik * x.licznik;
        MianownikPoRazy = mianownik * x.mianownik;
        cout << "* " << LicznikPoRazy / NWD(LicznikPoRazy, MianownikPoRazy) << "/" << MianownikPoRazy / NWD(LicznikPoRazy, MianownikPoRazy) << endl;
    }
    void Dziel(Ulamek& x)
    {
        int LicznikPoDziel, MianownikPoDziel;
        LicznikPoDziel = licznik * x.mianownik;
        MianownikPoDziel = mianownik * x.licznik;
        cout << "/ " << LicznikPoDziel / NWD(LicznikPoDziel, MianownikPoDziel) << "/" << MianownikPoDziel / NWD(LicznikPoDziel, MianownikPoDziel) << endl;
    }
    void Dodac(Ulamek& x)
    {
        int RozszerzanieUlamka1, RozszerzanieUlamka2, LicznikPoDodaj, MianownikPoDodaj;
        RozszerzanieUlamka1 = NWW(mianownik, x.mianownik) / mianownik;
        RozszerzanieUlamka2 = NWW(mianownik, x.mianownik) / x.mianownik;
        LicznikPoDodaj = (licznik * RozszerzanieUlamka1) + (x.licznik * RozszerzanieUlamka2);
        MianownikPoDodaj = NWW(mianownik, x.mianownik);
        cout << "+ " << LicznikPoDodaj / NWD(LicznikPoDodaj, MianownikPoDodaj) << "/" << MianownikPoDodaj / NWD(LicznikPoDodaj, MianownikPoDodaj) << endl;
    }
    void Odjac(Ulamek& x)
    {
        int RozszerzanieUlamka1, RozszerzanieUlamka2, LicznikPoOdjac, MianownikPoOdjac;
        RozszerzanieUlamka1 = NWW(mianownik, x.mianownik) / mianownik;
        RozszerzanieUlamka2 = NWW(mianownik, x.mianownik) / x.mianownik;
        LicznikPoOdjac = (licznik * RozszerzanieUlamka1) - (x.licznik * RozszerzanieUlamka2);
        MianownikPoOdjac = NWW(mianownik, x.mianownik);
        cout << "- " << LicznikPoOdjac / NWD(LicznikPoOdjac, MianownikPoOdjac) << "/" << MianownikPoOdjac / NWD(LicznikPoOdjac, MianownikPoOdjac) << endl;
    }
    bool mniejsze(Ulamek& x)
    {
        int RozszerzanieUlamka1, RozszerzanieUlamka2;
        RozszerzanieUlamka1 = NWW(mianownik, x.mianownik) / mianownik;
        RozszerzanieUlamka2 = NWW(mianownik, x.mianownik) / x.mianownik;
        licznik = licznik * RozszerzanieUlamka1;
        x.licznik = x.licznik * RozszerzanieUlamka2;
        if (licznik < x.licznik)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Minus()
    {
        // Dla zera zwraca 0
        if (licznik == 0 && mianownik == 0)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << licznik * -1 << "/" << mianownik << endl;
        }
    }
};
int main()
{
    Ulamek a(14, 5);
    Ulamek b(10, 2);
    a.WypiszUlamek();
    b.WypiszUlamek();
    a.Razy(b);
    a.Dziel(b);
    a.Dodac(b);
    a.Odjac(b);
    cout << a.mniejsze(b) << endl;
    a.Minus();
    return 0;
}