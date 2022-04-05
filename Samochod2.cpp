#include <iostream>
using namespace std;
class Samochod
{
private:
    string marka;
    string model;
    int przebieg;
    double paliwo;
    double spalanie;
public:
    Samochod()
    {
    }
    Samochod(string marka,string model, int przebieg)
    {
        this->marka=marka;
        this->model=model;
        this->przebieg=przebieg;
    }
    Samochod(string _marka, string _model)
        :marka(_marka),model(_model)
    {
        przebieg=0;
    }
    Samochod(string marka,string model,int przebieg,double paliwo,double spalanie)
    :marka(marka),model(model),przebieg(przebieg),paliwo(paliwo),spalanie(spalanie)
    {

    }

    void Wypisz() const
    {
        cout<<endl;
        cout<<"marka: "<<marka<<endl;
        cout<<"model: "<<model<<endl;
        cout<<"przebieg: "<<przebieg<<endl;
        cout<<"paliwo: "<<paliwo<<endl;
        cout<<"spalanie: "<<spalanie<<endl;

        cout<<endl;
    }
    void Jedz(int km)
    {
        if(km<paliwo/(spalanie/100))
        {
            przebieg+=km;
            paliwo-=(spalanie/100)*km;
        }
        else
        {
            cout<<"nie ma tyle paliwa zatankuj "<<endl;
        }

    }
    void inicjalizuj(string marka, string model, double przebieg)
    {
        this->marka=marka;
        this->model=model;
        this->przebieg=przebieg;
    }
    void Tankuj(double z)
    {
        paliwo+=z;
    }
    void setSpalanie(double Spalanie)
    {
        this->spalanie=Spalanie;
    }
    void setPaliwo(double Paliwo)
    {
        this->paliwo=Paliwo;
    }
};
int main()
{
    Samochod s1("Audi","A5",3000,50,3);
    Samochod s2;
    int i(5);
    cout<<i;

    s1.Wypisz();
    s1.Jedz(500);
    s1.Wypisz();

    s2.inicjalizuj("BMW","3gt",150);
    s2.Wypisz();

    const Samochod s3("Ford","Mustang",25000);
    s3.Wypisz();

    Samochod s4("Fiat","500L",125000,49,7);
    s4.Wypisz();
    s4.Jedz(100);
    s4.Wypisz();
    s4.Tankuj(20);
    s4.Wypisz();

    s1.setSpalanie(10);
    s1.Wypisz();
    s1.Tankuj(40);
}
