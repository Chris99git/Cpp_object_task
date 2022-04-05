#include <iostream>
using namespace std;
//ta klasa jest abstrakcyjna bo posiada co najmniej 1 funkcje abstrac (2)
//ta klasa zosta³a utworzona tylko po to ¿eby w klasie transport metoda wykonaj trase mog³a dzia³aæ dla samochodu osobowego i ciezarowego inaczej
class Samochod
{
protected:
    double spalanie;
    double amortyzacja;
public:
    Samochod(double _spalanie, double _amortyzacja)
        :spalanie(_spalanie),amortyzacja(_amortyzacja)
    {
    }
    //te funkcje s¹ abstrakcyjne bo nie maj¹ bloku i s¹ przyrównane od 0
    virtual double ObliczSpalanie(double liczbaKilometrow)=0;
    virtual double ObliczAmortyzacje(double liczbaKilometrow)=0;
};
class SamochodOsobowy: public Samochod
{
public:
    SamochodOsobowy(double _spalanie, double _amortyzacja)
        :Samochod(_spalanie,_amortyzacja)
    {
    }
    double ObliczSpalanie(double liczbaKilometrow)
    {
        return (liczbaKilometrow*spalanie)/100;
    }
    double ObliczAmortyzacje(double liczbaKilometrow)
    {
        return (liczbaKilometrow*amortyzacja)/100;
    }
};
class SamochodCiezarowy : public Samochod
{
private:
private:
    double ladownoscNaczepy;
    double ladownoscPrzyczepy;
public:
    SamochodCiezarowy(double _spalanie, double _amortyzacja, double _ladownoscNaczepy, double _ladownoscPrzyczepy)
        :Samochod(_spalanie, _amortyzacja), ladownoscNaczepy(_ladownoscNaczepy),ladownoscPrzyczepy(_ladownoscPrzyczepy)
    {

    }
    double ObliczSpalanie(double liczbaKilometrow)
    {
        return (liczbaKilometrow + ladownoscNaczepy + ladownoscPrzyczepy)*spalanie/100;
    }
    double ObliczAmortyzacje(double liczbaKilometrow)
    {
        return (liczbaKilometrow + ladownoscNaczepy + ladownoscPrzyczepy)*amortyzacja/100;
    }

};
class Transport
{
private:
    double kosztyPaliwa;
    double kosztyAmortyzacji;
public:
    Transport()
        :kosztyPaliwa(0),kosztyAmortyzacji(0)
    {
    }
    void WykonajTrase(Samochod& samochod, double liczbaKilometrow)
    {
        kosztyPaliwa += samochod.ObliczSpalanie(liczbaKilometrow);
        kosztyAmortyzacji += samochod.ObliczAmortyzacje(liczbaKilometrow);
    }
    void Wyswietl() const
    {
        cout<<endl<<"koszty paliwa: "<<kosztyPaliwa;
        cout<<endl<<"koszty amortyzacji: "<<kosztyAmortyzacji;
    }
};
int main()
{
    Transport transport;

//    Samochod s(10,10); nie mozna tworzyc obiektu klasy abstract

    SamochodOsobowy so(8,20);
    transport.WykonajTrase(so,100);

    SamochodCiezarowy sc(20,50,100,200);
    transport.WykonajTrase(sc,200);
    transport.Wyswietl();
}

