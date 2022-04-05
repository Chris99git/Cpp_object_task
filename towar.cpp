#include <iostream>
using namespace std;
class Towar
{
private: //poni¿sze pola bêd¹ u¿ywane tylko w kasie sa prywatne
    double cena;
    double waga;
public:     //ponizsze elementy beda u¿ywane w klasie i poza ni¹ zatem jest publiczne
    string nazwa; //bo nazwa jest u¿ywana w mainie czyli poza klas¹, wiec musi byc publiczna
    void wczytaj()
    {
        cout<<endl<<"Podaj nazwe ";
        getline(cin,nazwa);
        cout<<endl<<"Podaj cene ";
        cin>>cena;
        cout<<endl<<"Podaj wage ";
        cin>>waga;
    }
    void wypisz()
    {
        cout<<endl<<"nazwa "<<nazwa;
        cout<<endl<<"cena "<<cena;
        cout<<endl<<"waga "<<waga;
    }
    string getNazwa()
    {
        return nazwa;
    }
    void setImie(string nazwa)
    {
        this->nazwa=nazwa;
    }

    double getCena()
    {
        return cena;
    }
    void setCena(double cena)
    {
        this->cena=cena;
    }

    double getWaga()
    {
        return waga;
    }
    void setWaga(double waga)
    {
        this->waga=waga;
    }

    int UstawDaneTowaru()
    {
        cout<<"podaj now¹ nazwe: "<<getNazwa()<<endl;
        cout<<"podaj now¹ cene: "<<getCena()<<endl;
        cout<<"podaj now¹ wage: "<<getWaga()<<endl;
    }
    void inicjalizuj (string imie, string nazwisko, string miejscowosc, double placa)
    {
        this->imie=imie;
        this->nazwisko=nazwisko;
        this->miejscowosc=miejscowosc;
        this->placa=placa;

    }

};

main()
{
    Towar t1;
    Towar t2;
    t1.wczytaj();
    cout<<endl<<"nazwa towaru 1: "<<t1.nazwa;
    t1.wypisz();


    cout<<UstawDaneTowaru(t1);

}
