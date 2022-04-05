#include <iostream>
#include <iomanip>
using namespace std;
class Data
{
private:
    int dzien, miesiac, rok;
public:
    Data(int dzien, int miesiac, int rok)
        :dzien(dzien),miesiac(miesiac),rok(rok)
    {
        Wpisz(dzien, miesiac, rok);
    }
    void Wpisz(int dzien, int miesiac, int rok)
    {
        this->dzien = dzien;
        this->miesiac = miesiac;
        this->rok = rok;
    }
    void Prezentuj() const
    {
        cout << setw(2) << setfill('0') << dzien << "." << setw(2) << setfill('0') << miesiac << "." << rok << endl;
    }
};
class Student
{
private:
    string imie, nazwisko;
    int indeks;
    Data data_przyjecia;
public:
    Student(string _imie, string _nazwisko, int _indeks, int _dzien, int _miesiac, int _rok)
        : imie(_imie), nazwisko(_nazwisko), indeks(_indeks), data_przyjecia(_dzien, _miesiac, _rok)
    {
    }
    void Wyswietl() const
    {
        cout <<endl<< "Imie: " << imie;
        cout <<endl<< "Nazwisko: " << nazwisko;
        cout <<endl<< "Indeks: " << indeks;
        cout <<endl<<"Data przyjecia: ";
        data_przyjecia.Prezentuj();
    }
};
int main()
{
    Data d1(12, 11, 1999);
    d1.Prezentuj();
    d1.Wpisz(21, 10, 1979);
    d1.Prezentuj();
    Student s1("Ola", "Nowak", 1234, 12, 11, 1999);
    s1.Wyswietl();
    return 0;
}
