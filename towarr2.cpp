#include <iostream>
using namespace std;
class Towar
{
private:
    string nazwa;
    double cenaNetto;
    static int licznik;
public:
    Towar()
    {
        nazwa="Noname";
        licznik++;
    }
    Towar(string _nazwa, double _cenaNetto)
        :nazwa(_nazwa),cenaNetto(_cenaNetto)
    {
        cout<<"Tworzy towar: "<<nazwa<<endl;
        licznik++;
    }
    ~Towar()
    {
        cout<<endl<<"Towar "<<nazwa<<" "<<"zostal usuniety"<<endl;
        licznik--;
    }
    void Drukuj()const
    {
        cout<<endl<<nazwa<<" "<<cenaNetto;
    }
    static int LiczbaTowaru()
    {
        return licznik;
    }
    string getNazwa()
    {
        return nazwa;
    }
    void setNazwa(string _nazwa)
    {
        nazwa=_nazwa;
    }
    double getCenaNetto()
    {
        return cenaNetto;
    }
    void setcenaNetto(double _cenaNetto)
    {
        cenaNetto=_cenaNetto;
    }
};
int Towar::licznik = 0; //kluczowe
int main()
{
    Towar* banan= new Towar("banan",3);
    banan->Drukuj();
    cout<<endl<<"Liczba Towaru: "<<Towar::LiczbaTowaru();
    Towar t1("jabko",12);
    {
        Towar t3("mydlo ",6);
        t3.Drukuj();
        Towar* gruszka=new Towar ("gruszka",2);
        gruszka->Drukuj();
        cout<<endl<<"Liczba Towaru: "<<Towar::LiczbaTowaru();
        delete gruszka;
    }
    Towar t2("Ptasie Mleczko ",14);
    t1.Drukuj();
    cout<<endl<<"Liczba Towaru: "<<t1.LiczbaTowaru();
    t2.Drukuj();
//    t3.Drukuj();
    cout<<endl<<"Liczba Towaru: "<<t2.LiczbaTowaru();
    Towar* jabko= new Towar("banan",3);
    banan->Drukuj();
    delete banan;
    int n=5;
    Towar*tab=new Towar[n]; //tablica musi byc konstruktor domniemany
    delete []tab;
    const Towar t5("oliwki ",5);
    //nie mozna zmieniac towaru stalego
    t5.Drukuj();
}
