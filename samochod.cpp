#include <iostream>
using namespace std;
class Samochod
{
private:
    string marka;
    string model;
    double cena;
    double przebieg;
    const string numerNadwozia;
public:
  	Samochod();
  	Samochod(string marka, string model, double cena, double przebieg, string numer);
    void Wyswietl()const;
    friend void ZmienCene(Samochod& x);
	friend void WyswietlModelICene(Samochod x);
};
Samochod::Samochod()
{
}
Samochod::Samochod(string marka, string model, double cena,
	double przebieg, string numer)
: marka(marka), model(model), cena(cena),
przebieg(przebieg), numerNadwozia(numer)
{
}
void Samochod::Wyswietl()const
{
    cout<<"Marka: "<<marka<<"Model: "<<model<<"Cena: "<<cena<<"Przebieg: "<<przebieg<<"Numer nadwozia: "<<numerNadwozia<<endl;
}
void ZmienCene(Samochod& x)
{
	cin>> x.cena;
}
void WyswietlModelICene(Samochod x)
{
	cout<<endl<<x.marka<<" "<<x.model;
}
int main()
{
	Samochod s1("Mazda","323f",15000,215000,"AS123asda4jh");
	s1.Wyswietl();
	ZmienCene(s1);
	s1.Wyswietl();
	WyswietlModelICene(s1);
	const Samochod s2("Ford","Mustang",25000,20000,"ewyuw6");
    s2.Wyswietl();
    WyswietlModelICene(s2);
    Samochod* s3 = new Samochod("Opel", "Astra", 54054, 6436, "4326k");
    s3->Wyswietl();
    delete s3;
    int n=4;
    Samochod* tab=new Samochod[n];
    delete[] tab;
//    tab[0]->Wyswietl();
}
