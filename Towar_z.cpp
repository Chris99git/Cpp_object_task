#include <iostream>
using namespace std;
class Towar
{
private:
    string nazwa;
    double cena;
    double waga;
public:
    void Wypisz()
    {
        cout<<endl;
        cout<<"Nazwa: "<<nazwa<<endl;;
        cout<<"Cena: "<<cena<<endl;;
        cout<<"Waga: "<<waga<<endl;
        cout<<endl;
    }
    void Wpisz()
    {
        cout<<"Podaj nazwe: "<<endl;
        cin>>nazwa;
        cout<<"Podaj cene: "<<endl;
        cin>>cena;
        cout<<"Podaj wage: "<<endl;
        cin>>waga;
        cout<<endl;
    }
    void SetNazwa(string nazwa)
    {
        this->nazwa = nazwa;
    }
    void SetCena(double cena)
    {
        this->cena = cena;
    }
    void SetWaga(double waga)
    {
        this->waga = waga;
    }
    string GetNazwa()
    {
        return nazwa;
    }
    double GetCena()
    {
        return cena;
    }
    double GetWaga()
    {
        return waga;
    }
    void UstawDaneTowaru(string nazwa, double cena, double waga)
    {
        this->nazwa=nazwa;
        this->cena=cena;
        this->waga=waga;
    }
    void ZwiekszCene(double cena_i)
    {
        this->cena+=cena_i;
    }
};
int main()
{
    Towar t1;
    t1.UstawDaneTowaru("jabko",4,1);
    t1.Wypisz();
    t1.ZwiekszCene(5);
    t1.Wypisz();
}
