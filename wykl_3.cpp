#include <iostream>
using namespace std;
class Postac
{
private:
    string nazwa;
    int poziom;
    int hp;
    static int liczbaPostaci; // to jest pole statyczne kazda postac ma te sama wartosc tego pola
public:
    Postac(string _nazwa,int _poziom,int _hp)
        :nazwa(_nazwa),poziom(_poziom),hp(_hp)
    {
        liczbaPostaci++; //przy ka�dym utwo�eniu postaci wywo�uje si� konstruktor ktorym zwi�kszamy liczb� postaci
    }
    //to jest metoda sta�a ona wy�wietla nie zmienia obiektu
    void Wyswietl()const
    {
        cout<<nazwa<<endl;
        cout<<poziom<<endl;
        cout<<hp<<endl;
    }
    static int PobierzLiczbePostaci()
    {
        return liczbaPostaci;
    }
};
//pole statyczne inicjalizujemy poza klasa
int Postac::liczbaPostaci=0;
int main()
{
    Postac p1("Zajac", 5, 100);
    p1.Wyswietl();

    Postac p2("Zajac", 2, 2);
    p2.Wyswietl();

    Postac p3("Zajac", 3, 3);
    p3.Wyswietl();

    cout<<endl<<"Liczba postaci z p3: "<<p3.PobierzLiczbePostaci();
    cout<<endl<<"Liczba postaci z p2: "<<p2.PobierzLiczbePostaci();
    cout<<endl<<"Liczba postaci z p1: "<<p1.PobierzLiczbePostaci();
    cout<<endl<<"Liczba postaci z klasy postac: "<<Postac::PobierzLiczbePostaci();
}
